#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSerialPort>
#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QDateTime>
#include <QFileDialog>
#include <QStandardPaths>
#include <QFile>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    m_state(WaitHeader1)
{
    ui->setupUi(this);
    serial=new QSerialPort(this);
    m_showtime=false;//先初始值
    m_hexShow=false;
    m_saveToFile=false;
    m_pauseDisplay=false;
    m_appendNewLine=false;
    m_useFileSource=false; // 是否启用文件数据源
    timer=new QTimer(this);
    timer->setInterval(1000);

    m_recvTotal=0;//初始化发送和接收
    m_sendTotal=0;
    m_labSerialStatus=new QLabel(" 串口状态：已关闭 ");
    m_labSerialInfo=new QLabel(" 未打开 ");
    m_labRecvCount=new QLabel(" 接收：0 字节 ");
    m_labSendCount=new QLabel(" 发送：0 字节 ");
    ui->statusbar->addWidget(m_labSerialStatus);
    ui->statusbar->addWidget(m_labSerialInfo);
    ui->statusbar->addPermanentWidget(m_labRecvCount);
    ui->statusbar->addPermanentWidget(m_labSendCount);

    // 初始样式（可选，更美观）
    m_labSerialStatus->setStyleSheet("color:red; font-weight:bold;");

    connect(ui->chkShowTime,&QCheckBox::clicked,this,[=](bool checked){
        m_showtime=checked;//监听是否显示时间复选框
    });
    connect(ui->chkHexShow,&QCheckBox::clicked,this,[=](bool checked){
        m_hexShow=checked;//监听是否选上十六进制复选框
    });
    connect(ui->chkRecvSaveFile,&QCheckBox::clicked,this,[=](bool checked){
        m_saveToFile=checked;//监听是否选上输出到文件
        if (m_saveToFile){
            m_recvFile.setFileName("recv_log.txt");
            if (!m_recvFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
                qDebug()<<"打开错误:"<<m_recvFile.errorString();
            }
        }else{
            if ( m_recvFile.isOpen()){
                m_recvFile.close();
            }
        }
    });
    connect(ui->chkPauseShow,&QCheckBox::clicked,this,[=](bool checked){
        m_pauseDisplay=checked;//监听是否选上不显示消息
    });
    connect(ui->chkAutoAppend,&QCheckBox::clicked,this,[=](bool checked){
        m_appendNewLine=checked;//监听是否自动添加末尾符
    });
    connect(ui->chkFileSource,&QCheckBox::toggled,this,&MainWindow::FileSourceToggled);//选取数据源发送

    connect(timer,&QTimer::timeout,this,&MainWindow::on_m_sendbutton_clicked);//定时器循环发送
    connect(ui->chkLoopSend,&QCheckBox::clicked,this,[=](bool checked){//要是监听到了需要循环发送就触发timer的信号，信号触发信号
        if(checked){
            timer->start();
        }else{
            timer->stop();
        }
    });
}

MainWindow::~MainWindow()
{
    if (m_recvFile.isOpen()){
        m_recvFile.close();
    }
    delete ui;
}
void MainWindow::on_m_stopbutton_clicked(){
    if (serial->isOpen()){//设置默认关闭
        serial->close();
        ui->m_stopbutton->setText("打开");
        ui->comboBox->setEnabled(true);
        ui->comboBox_2->setEnabled(true);
        ui->comboBox_3->setEnabled(true);
        ui->comboBox_4->setEnabled(true);
        ui->comboBox_5->setEnabled(true);
        m_labSerialStatus->setText(" 串口状态：已关闭 ");//关闭串口更新状态栏
        m_labSerialStatus->setStyleSheet("color:red; font-weight:bold;");
        m_labSerialInfo->setText(" 未打开 ");
    }else{//读取参数
        //串口号和波特率,除了串口号其他都是枚举数据类型
        QString portName=ui->comboBox->currentText();
        qint32 bot=ui->comboBox_2->currentText().toInt();
        //校验位
        QSerialPort::Parity parity;
        QString yan=ui->comboBox_3->currentText();
        if (yan=="NONE"){
            parity=QSerialPort::NoParity;
        }else if(yan=="Even"){
            parity=QSerialPort::EvenParity;
        }else{
            parity=QSerialPort::OddParity;
        }
        //数据位
        QSerialPort::DataBits data=static_cast<QSerialPort::DataBits> (ui->comboBox_4->currentText().toInt());
        //停止位
        QSerialPort::StopBits stop;
        QString stopbit=ui->comboBox_5->currentText();
        if (stopbit=="1"){
            stop=QSerialPort::OneStop;
        }else if (stopbit=="1.5"){
            stop=QSerialPort::OneAndHalfStop;
        }else{
            stop=QSerialPort::TwoStop;
        }
        serial->setPortName(portName);
        serial->setBaudRate(bot);
        serial->setParity(parity);
        serial->setDataBits(data);
        serial->setStopBits(stop);
        //串口连接状态下监听消息
        if(serial->open(QIODevice::ReadWrite)){
            qDebug() << "串口打开成功";
            connect(serial,&QSerialPort::readyRead,this,&MainWindow::receive_add);//监听串口，有消息就接受消息
            ui->m_stopbutton->setText("关闭");
            ui->comboBox->setEnabled(false);
            ui->comboBox_2->setEnabled(false);
            ui->comboBox_3->setEnabled(false);
            ui->comboBox_4->setEnabled(false);
            ui->comboBox_5->setEnabled(false);
            m_labSerialStatus->setText(" 串口状态：已打开 ");//更新状态栏
            m_labSerialStatus->setStyleSheet("color:green; font-weight:bold;");
            m_labSerialInfo->setText(QString(" 端口：%1  波特率：%2 ").arg(serial->portName()).arg(serial->baudRate()));
        }else{
            QMessageBox::critical(this,"错误","没打开:"+serial->errorString());
        }

    }
}
void MainWindow::on_m_sendbutton_clicked(){
    if (serial->isOpen()){
        QByteArray totalData = ui->m_send->toPlainText().toUtf8();
        if (m_appendNewLine){
            totalData.append("\r\n");//是否在末尾添加标识符
        }
        const int MAX_LEN=255;
        int index=0;
        while(index<totalData.size()){//超过255个字节就分包发送
            QByteArray txt_part=totalData.mid(index,MAX_LEN);
            index+=txt_part.size();

            QByteArray frame;
            frame.append(0xAA);
            frame.append(0x55);
            frame.append(txt_part.size());
            frame.append(txt_part);
            frame.append(calcCheckSum(txt_part));      // 校验,其实也要两个针头和长度加一起计算的
            serial->write(frame);
            QThread::msleep(20);//设置间隔时间，给硬件发送时间,给硬件点缓存时间
            // 发送计数更新
            m_sendTotal += totalData.size();
            m_labSendCount->setText(QString(" 发送：%1 字节 ").arg(m_sendTotal));
        }
    }else{
        QMessageBox::warning(this, "警告", "串口未打开");
        return;
    }
    if( ui->chkAutoClear->isChecked()){//选择是否清空发送框
        ui->m_send->clear();
        ui->chkFileSource->setChecked(false);//要是清空发送框的话，循环发送和选取文件发送就得改变状态了
        ui->chkLoopSend->setChecked(false);
    }
}
void MainWindow::receive_add()
{
    qDebug() << "收到消息";
    m_arry.append(serial->readAll());
    int i=0;
    while (i<m_arry.size()){//状态机实现
        quint8 byte=static_cast<quint8>(m_arry[i]);
        switch (m_state) {
        case WaitHeader1:
            if(byte==0xAA){
                m_state=WaitHeader2;
            }
            i++;
            break;
        case WaitHeader2:
            if(byte==0x55){
                m_state=WaitLength;
            }else{
                m_state=WaitHeader1;
            }
            i++;
            break;
        case WaitLength:
            m_datalen=byte;
            m_data.clear();
            m_state=WaitData;
            i++;
            break;
        case WaitData:
            if (m_data.size()<m_datalen){//按照长度来接收数据，而不是碰到校验码就停止
                m_data.append(byte);
                i++;
            }else if (m_data.size()==m_datalen){
                m_state=WaitCheck;
            }
            break;
        case WaitCheck:
            quint8 sender_check=byte;
            quint8 m_check=calcCheckSum(m_data);
            if(sender_check==m_check){
                QString data = QString::fromUtf8(m_data);
                if (m_hexShow){//如果复选框选上了就把数据转十六进制
                    data = m_data.toHex(' ');
                }
                if (m_showtime){//如果复选框选上了就在数据前加当前时间
                    data = QDateTime::currentDateTime().toString("[hh:mm:ss.zzz] ")+data;
                }
                if(!m_pauseDisplay){
                    ui->m_receive->moveCursor(QTextCursor::End);//没选不显示复选框就正常显示,用append的话会自动换行，数据不完整
                    ui->m_receive->insertPlainText(data);
                    m_recvTotal += m_data.size();
                    m_labRecvCount->setText(QString(" 接收：%1 字节 ").arg(m_recvTotal));
                }
                if (m_saveToFile &&m_recvFile.isOpen()){//将内容输出到文件
                    QTextStream out_file(&m_recvFile);
                    out_file<<data<<'\n';
                    out_file.flush();//立即输入
                }
            }
            m_data.clear();
            m_state=WaitHeader1;
            i++;
            break;
        }
    }
    if(i>0){
        m_arry.remove(0,i);
    }

}
quint8  MainWindow::calcCheckSum(const QByteArray &data){
    quint8 sum=0;
    for (char c:data){
        sum+=static_cast<quint8>(c);
    }
    return sum;
}


void MainWindow::FileSourceToggled(bool checked){//数据源
    m_useFileSource = checked;
    qDebug()<<"选取文件";
    if (!m_useFileSource){
        m_fileDataSource.clear();
        ui->m_send->clear();
        return;
    }                                                       //动态获取桌面地址
    QString FileName=QFileDialog::getOpenFileName(this,"选取数据来源",QStandardPaths::writableLocation(QStandardPaths::DesktopLocation),"文本文件 (*.txt)");
    if (FileName.isEmpty()){
        m_useFileSource=false;
        ui->chkFileSource->setChecked(false);
        return;
    }
    QFile file(FileName);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        m_fileDataSource=file.readAll();
        file.close();
    }else{
        qDebug() << "文件打开失败：" << file.errorString();
        m_useFileSource = false;
        ui->chkFileSource->setChecked(false);
        return;
    }
    ui->m_send->setPlainText(QString::fromUtf8(m_fileDataSource));
}