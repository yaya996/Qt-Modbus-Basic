/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *m_sendbutton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *m_ck;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *m_bt;
    QComboBox *comboBox_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *m_jy;
    QComboBox *comboBox_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *m_sj;
    QComboBox *comboBox_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *m_tz;
    QComboBox *comboBox_5;
    QPushButton *m_stopbutton;
    QWidget *m_jsqsz;
    QVBoxLayout *verticalLayout_2;
    QCheckBox *chkSendStateMachine;
    QCheckBox *chkRecvSaveFile;
    QCheckBox *chkShowTime;
    QCheckBox *chkHexShow;
    QCheckBox *chkPauseShow;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *chkRecvStateMachine;
    QCheckBox *chkFileSource;
    QCheckBox *chkAutoAppend;
    QCheckBox *chkAutoClear;
    QCheckBox *chkLoopSend;
    QTextEdit *m_receive;
    QLabel *label_3;
    QTextEdit *m_send;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(942, 749);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        m_sendbutton = new QPushButton(centralwidget);
        m_sendbutton->setObjectName("m_sendbutton");
        m_sendbutton->setGeometry(QRect(710, 510, 91, 61));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(30, 20, 156, 568));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        m_ck = new QLabel(layoutWidget);
        m_ck->setObjectName("m_ck");

        horizontalLayout->addWidget(m_ck);

        comboBox = new QComboBox(layoutWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        m_bt = new QLabel(layoutWidget);
        m_bt->setObjectName("m_bt");

        horizontalLayout_2->addWidget(m_bt);

        comboBox_2 = new QComboBox(layoutWidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        horizontalLayout_2->addWidget(comboBox_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        m_jy = new QLabel(layoutWidget);
        m_jy->setObjectName("m_jy");

        horizontalLayout_3->addWidget(m_jy);

        comboBox_3 = new QComboBox(layoutWidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");

        horizontalLayout_3->addWidget(comboBox_3);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        m_sj = new QLabel(layoutWidget);
        m_sj->setObjectName("m_sj");

        horizontalLayout_4->addWidget(m_sj);

        comboBox_4 = new QComboBox(layoutWidget);
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->addItem(QString());
        comboBox_4->setObjectName("comboBox_4");

        horizontalLayout_4->addWidget(comboBox_4);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        m_tz = new QLabel(layoutWidget);
        m_tz->setObjectName("m_tz");

        horizontalLayout_5->addWidget(m_tz);

        comboBox_5 = new QComboBox(layoutWidget);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");

        horizontalLayout_5->addWidget(comboBox_5);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_4->addLayout(verticalLayout);

        m_stopbutton = new QPushButton(layoutWidget);
        m_stopbutton->setObjectName("m_stopbutton");
        m_stopbutton->setIconSize(QSize(20, 5));

        verticalLayout_4->addWidget(m_stopbutton);

        m_jsqsz = new QWidget(layoutWidget);
        m_jsqsz->setObjectName("m_jsqsz");
        verticalLayout_2 = new QVBoxLayout(m_jsqsz);
        verticalLayout_2->setObjectName("verticalLayout_2");
        chkSendStateMachine = new QCheckBox(m_jsqsz);
        chkSendStateMachine->setObjectName("chkSendStateMachine");

        verticalLayout_2->addWidget(chkSendStateMachine);

        chkRecvSaveFile = new QCheckBox(m_jsqsz);
        chkRecvSaveFile->setObjectName("chkRecvSaveFile");

        verticalLayout_2->addWidget(chkRecvSaveFile);

        chkShowTime = new QCheckBox(m_jsqsz);
        chkShowTime->setObjectName("chkShowTime");

        verticalLayout_2->addWidget(chkShowTime);

        chkHexShow = new QCheckBox(m_jsqsz);
        chkHexShow->setObjectName("chkHexShow");

        verticalLayout_2->addWidget(chkHexShow);

        chkPauseShow = new QCheckBox(m_jsqsz);
        chkPauseShow->setObjectName("chkPauseShow");

        verticalLayout_2->addWidget(chkPauseShow);


        verticalLayout_4->addWidget(m_jsqsz);

        widget = new QWidget(layoutWidget);
        widget->setObjectName("widget");
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setObjectName("verticalLayout_3");
        chkRecvStateMachine = new QCheckBox(widget);
        chkRecvStateMachine->setObjectName("chkRecvStateMachine");

        verticalLayout_3->addWidget(chkRecvStateMachine);

        chkFileSource = new QCheckBox(widget);
        chkFileSource->setObjectName("chkFileSource");

        verticalLayout_3->addWidget(chkFileSource);

        chkAutoAppend = new QCheckBox(widget);
        chkAutoAppend->setObjectName("chkAutoAppend");

        verticalLayout_3->addWidget(chkAutoAppend);

        chkAutoClear = new QCheckBox(widget);
        chkAutoClear->setObjectName("chkAutoClear");

        verticalLayout_3->addWidget(chkAutoClear);

        chkLoopSend = new QCheckBox(widget);
        chkLoopSend->setObjectName("chkLoopSend");

        verticalLayout_3->addWidget(chkLoopSend);


        verticalLayout_4->addWidget(widget);

        m_receive = new QTextEdit(centralwidget);
        m_receive->setObjectName("m_receive");
        m_receive->setGeometry(QRect(200, 20, 601, 481));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 700, 69, 19));
        m_send = new QTextEdit(centralwidget);
        m_send->setObjectName("m_send");
        m_send->setGeometry(QRect(200, 510, 501, 61));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 942, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        m_sendbutton->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
        m_ck->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243\345\217\267", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "COM1", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "COM2", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "COM3", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "COM4", nullptr));

        m_bt->setText(QCoreApplication::translate("MainWindow", " \346\263\242\347\211\271\347\216\207", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "9600", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "19200", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "38400", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "115200", nullptr));
        comboBox_2->setItemText(4, QCoreApplication::translate("MainWindow", "460800", nullptr));

        m_jy->setText(QCoreApplication::translate("MainWindow", "\346\240\241\351\252\214\344\275\215", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "None", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "Even", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "Odd", nullptr));

        m_sj->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\344\275\215", nullptr));
        comboBox_4->setItemText(0, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_4->setItemText(1, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_4->setItemText(2, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_4->setItemText(3, QCoreApplication::translate("MainWindow", "8", nullptr));

        m_tz->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\344\275\215", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "1.5", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));

        m_stopbutton->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        chkSendStateMachine->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\272\345\217\221\351\200\201", nullptr));
        chkRecvSaveFile->setText(QCoreApplication::translate("MainWindow", "\346\216\245\346\224\266\350\275\254\345\220\221\346\226\207\344\273\266", nullptr));
        chkShowTime->setText(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\346\216\245\346\224\266\346\227\266\351\227\264", nullptr));
        chkHexShow->setText(QCoreApplication::translate("MainWindow", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        chkPauseShow->setText(QCoreApplication::translate("MainWindow", "\346\232\202\345\201\234\346\216\245\345\217\227\346\230\276\347\244\272", nullptr));
        chkRecvStateMachine->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\346\234\272\346\216\245\346\224\266", nullptr));
        chkFileSource->setText(QCoreApplication::translate("MainWindow", "\345\220\257\347\224\250\346\226\207\344\273\266\346\225\260\346\215\256\346\272\220", nullptr));
        chkAutoAppend->setText(QCoreApplication::translate("MainWindow", "\350\207\252\345\212\250\345\217\221\351\200\201\351\231\204\345\212\240\344\270\272", nullptr));
        chkAutoClear->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\345\256\214\350\207\252\346\270\205\347\251\272", nullptr));
        chkLoopSend->setText(QCoreApplication::translate("MainWindow", "\346\225\260\346\215\256\346\265\201\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
