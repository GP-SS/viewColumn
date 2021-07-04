/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include "../../qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *customPlot;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QTextBrowser *text_receive;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QTextEdit *text_send;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QCheckBox *che_hex;
    QPushButton *btn_connect;
    QLabel *label_2;
    QLineEdit *edt_port;
    QPushButton *btn_send;
    QLineEdit *edt_ipaddress;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1120, 624);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        customPlot = new QCustomPlot(centralwidget);
        customPlot->setObjectName(QString::fromUtf8("customPlot"));
        customPlot->setGeometry(QRect(10, 10, 761, 561));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(790, 11, 322, 561));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        text_receive = new QTextBrowser(groupBox);
        text_receive->setObjectName(QString::fromUtf8("text_receive"));

        gridLayout_3->addWidget(text_receive, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout = new QGridLayout(groupBox_3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        text_send = new QTextEdit(groupBox_3);
        text_send->setObjectName(QString::fromUtf8("text_send"));

        gridLayout->addWidget(text_send, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 2);

        che_hex = new QCheckBox(groupBox_2);
        che_hex->setObjectName(QString::fromUtf8("che_hex"));

        gridLayout_2->addWidget(che_hex, 4, 2, 1, 1);

        btn_connect = new QPushButton(groupBox_2);
        btn_connect->setObjectName(QString::fromUtf8("btn_connect"));

        gridLayout_2->addWidget(btn_connect, 4, 0, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 2, 1, 1);

        edt_port = new QLineEdit(groupBox_2);
        edt_port->setObjectName(QString::fromUtf8("edt_port"));

        gridLayout_2->addWidget(edt_port, 1, 2, 1, 1);

        btn_send = new QPushButton(groupBox_2);
        btn_send->setObjectName(QString::fromUtf8("btn_send"));

        gridLayout_2->addWidget(btn_send, 4, 1, 1, 1);

        edt_ipaddress = new QLineEdit(groupBox_2);
        edt_ipaddress->setObjectName(QString::fromUtf8("edt_ipaddress"));

        gridLayout_2->addWidget(edt_ipaddress, 1, 0, 1, 2);


        gridLayout_4->addWidget(groupBox_2, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1120, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QApplication::translate("MainWindow", "\346\216\245\346\224\266\347\252\227\345\217\243", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\345\217\221\351\200\201\347\252\227\345\217\243", nullptr));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\347\275\221\347\273\234\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        che_hex->setText(QApplication::translate("MainWindow", "HEX\346\230\276\347\244\272", nullptr));
        btn_connect->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245\346\234\215\345\212\241\347\253\257", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243\345\217\267", nullptr));
        btn_send->setText(QApplication::translate("MainWindow", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
