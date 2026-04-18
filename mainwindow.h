#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSerialPort>
#include <QMainWindow>
#include <QStatusBar>
#include <QLabel>
#include <QFile>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;


private slots:
    void on_m_stopbutton_clicked();
    void on_m_sendbutton_clicked();
    void receive_add();
    void FileSourceToggled(bool checked);//选取数据源文件发送
private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QByteArray m_arry;//缓存
    QTimer *timer;//定时器循环发送
    //添加状态机
    enum ParseState {
        WaitHeader1,
        WaitHeader2,
        WaitLength,
        WaitData,
        WaitCheck
    };
    ParseState m_state;//状态
    quint8 m_datalen;
    QByteArray m_data;
    quint8 calcCheckSum(const QByteArray &data);

    // 状态栏标签
    QLabel *m_labSerialStatus;// 串口状态
    QLabel *m_labSerialInfo;// 串口信息
    QLabel *m_labRecvCount;// 接收计数
    QLabel *m_labSendCount;// 发送计数
    quint64 m_recvTotal;//计数变量
    quint64 m_sendTotal;

    bool m_showtime;//是否显示时间
    bool m_hexShow; //是否显示十六进制
    bool m_saveToFile;//是否保存到文件
    QFile m_recvFile;
    bool m_pauseDisplay;//是否显示到接收框
    bool m_appendNewLine;//是否自动添加末尾符
    bool m_useFileSource; // 是否启用文件数据源
    QByteArray m_fileDataSource;


};
#endif // MAINWINDOW_H
