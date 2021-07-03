#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupDynamicData(ui->customPlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupDynamicData(QCustomPlot *customPlot)
{
    QCPAxis *keyAxis = customPlot->xAxis;
    QCPAxis *valueAxis = customPlot->yAxis;
    QCPBars *height = new QCPBars(keyAxis, valueAxis);  // 使用xAxis作为柱状图的key轴，yAxis作为value轴

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
    valueAxis->setLabel("Height");
    valueAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);

    QVector<double> datay;
    for (int i = 0; i < 16; ++i) {
        datay.insert(0, QRandomGenerator::global()->bounded(10));//产生10以内的随机数
        //insert函数中的第一个参数表示从位置0的位置插入数据，即在数组的开头依次插入16个10以内的随机数
    }

    height->setData(ticks, datay);//根据传入的横纵坐标的值进行数据的设置

    connect(dataTimer, SIGNAL(timeout()), this, SLOT(dynamicDataSlot()));
    dataTimer->start(2000);// 2秒刷新一次
}

void MainWindow::dynamicDataSlot()
{

    QCPBars *bar = static_cast<QCPBars *>(ui->customPlot->plottable(0));
    bar->data()->clear();

    QVector<double> datay;
    for (int i = 0; i < 16; ++i) {
        datay.insert(0, QRandomGenerator::global()->bounded(10));//产生10以内的随机数
    }
    bar->setData(mPositions, datay);

    ui->customPlot->replot();//修改之后，需要调用replot()进行重绘
}


