#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "custombars.h"

#include <QTcpSocket>
#include <QHostAddress> //QHostAddress类提供一个IP地址。 这个类提供一种独立于平台和协议的方式来保存IPv4和IPv6地址

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setupDynamicData(QCustomPlot *customPlot);

public slots:
    void dynamicDataSlot();

private slots:
    //客户端槽函数

    void ClientRecvData();

    void on_btn_connect_clicked();

    void on_btn_send_clicked();

private:
    Ui::MainWindow *ui;

    QVector<QString> mLabels;
    QVector<double> mPositions;
    QVector<double> mHeight;
    QVector<double> mTicks;

    //QTimer *dataTimer = new QTimer();//如果只是定义一个指针变量，不进行任何初始化，该指针变成野指针，程序会崩掉；形如QTimer *dataTimer;

    QTcpSocket *mp_clientSocket = NULL;

};
#endif // MAINWINDOW_H
