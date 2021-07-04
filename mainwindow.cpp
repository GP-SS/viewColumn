#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupDynamicData(ui->customPlot);

    ui->edt_ipaddress->setText("127.0.0.1");
        ui->edt_port->setText("5550");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupDynamicData(QCustomPlot *customPlot)
{
    QCPAxis *keyAxis = customPlot->xAxis;
    QCPAxis *valueAxis = customPlot->yAxis;
    //QCPBars *height = new QCPBars(keyAxis, valueAxis);  // 使用xAxis作为柱状图的key轴，yAxis作为value轴
    CustomBars *height = new CustomBars(keyAxis, valueAxis);

    height->setAntialiased(false); // 为了更好的边框效果，关闭抗齿锯
    height->setName("控制棒高度"); // 设置柱状图的名字，可在图例中显示
    height->setPen(QPen(QColor(0, 168, 140).lighter(130))); // 设置柱状图的边框颜色
    height->setBrush(QColor(0, 168, 140));  // 设置柱状图的画刷颜色

    QVector<double> ticks;
    QVector<QString> labels;

    for (int i = 1; i < 17; ++i ) {
        ticks.push_back(i);
    }

    //ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    for(int j = 1; j < 17; ++j) {
        QString temp;
        temp = temp.sprintf("%d", j);
        labels.push_back("CR"+temp);
    }

    //labels << "CR1" << "CR2" << "CR3" << "CR4" << "CR5" << "CR6" << "CR7";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);

    mPositions = ticks;
    //mLabels = labels;

    keyAxis->setTicker(textTicker);        // 设置为文字轴
    //keyAxis->setTickLabelRotation(60);     // 轴刻度文字旋转60度
    keyAxis->setSubTicks(false);           // 不显示子刻度
    keyAxis->setTickLength(0, 2);          // 轴内外刻度的长度分别是0,4,也就是轴内的刻度线不显示
    keyAxis->setRange(0, 17);               // 设置范围
    keyAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    valueAxis->setRange(0, 10);
    valueAxis->setPadding(35);             // 轴的内边距，可以到QCustomPlot之开始（一）看图解
    valueAxis->setLabel("Height/cm");
    valueAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QVector<double> datay;
    for (int i = 0; i < 16; ++i) {
        datay.insert(0, QRandomGenerator::global()->bounded(10));//产生10以内的随机数
        //insert函数中的第一个参数表示从位置0的位置插入数据，即在数组的开头依次插入16个10以内的随机数
    }

    height->setData(ticks, datay);//根据传入的横纵坐标的值进行数据的设置

//    connect(dataTimer, SIGNAL(timeout()), this, SLOT(dynamicDataSlot()));
//    dataTimer->start(2000);// 2秒刷新一次
}

void MainWindow::dynamicDataSlot()
{

    CustomBars *bar = static_cast<CustomBars *>(ui->customPlot->plottable(0));
    bar->data()->clear();

    QVector<double> datay;
    for (int i = 0; i < 16; ++i) {
        datay.insert(0, QRandomGenerator::global()->bounded(10));//产生10以内的随机数
    }
    bar->setData(mPositions, datay);

    ui->customPlot->replot();//修改之后，需要调用replot()进行重绘
}



void MainWindow::on_btn_send_clicked()
{
    //获取TextEdit控件中的内容
   QString sendMsg = ui->text_send->toPlainText();
   char sendMsgChar[1024] = {0};
   strcpy_s(sendMsgChar, sendMsg.toStdString().c_str());
   int sendRe = mp_clientSocket->write(sendMsgChar, strlen(sendMsgChar));
   if(sendRe == -1)
   {
        QMessageBox::information(this, "QT网络通信", "向服务端发送数据失败！");
        return;
   }
}


void MainWindow::on_btn_connect_clicked()
{
    mp_clientSocket = new QTcpSocket();//建立TCP类的对象

    QString ip = ui->edt_ipaddress->text();\
    int port = ui->edt_port->text().toInt();

    mp_clientSocket->connectToHost(ip, port);
    if(!mp_clientSocket->waitForConnected(30000))
    {
        QMessageBox::information(this, "QT网络通信", "连接服务端失败！");
        return;
    }
    connect(mp_clientSocket, SIGNAL(readyRead()), this, SLOT(ClientRecvData()));
}

void MainWindow::ClientRecvData()
{
    //将之前的数据清空
    CustomBars *bar = static_cast<CustomBars *>(ui->customPlot->plottable(0));
    bar->data()->clear();


    //将接收内容存储到字符串中
    char recvMsg[1024] = {0};
    int recvRe = mp_clientSocket->read(recvMsg, 1024);
    if(recvRe == -1)
    {
        QMessageBox::information(this, "QT网络通信", "接收服务端数据失败！");
        return;
    }
    QString showQstr = recvMsg;
    //string showQstr = recvMsg;
    ui->text_receive->append(showQstr);

    QVector<double> data;//用于存储接收的数据的double格式
    //需要将字符串形式的数据转换成double类型
    auto list = showQstr.split(",");//list是字符串数组类型QStringList，showStr调用split函数将原始长的字符串数据根据逗号“,”进行分割，并将分割后的单独字符串依次存储在字符串数组中
    int len = list.size();
    for(int i = 0; i < len; ++i)
    {
        data.push_back(list[i].toDouble());//将字符串数据转换成double数据类型
    }

    //对柱状图设置数据
    bar->setData(mPositions, data);
    ui->customPlot->replot();//修改之后，需要调用replot()进行重绘
}

