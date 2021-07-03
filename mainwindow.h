#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"
#include "custombars.h"

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

private:
    Ui::MainWindow *ui;

    QVector<QString> mLabels;
    QVector<double> mPositions;
    QVector<double> mHeight;
    QVector<double> mTicks;

    QTimer *dataTimer = new QTimer();//如果只是定义一个指针变量，不进行任何初始化，该指针变成野指针，程序会崩掉；形如QTimer *dataTimer;

    int mIndex;
};
#endif // MAINWINDOW_H
