#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_timer = new QTimer();
    m_myobject = new MyObject();

    qDebug() << "mainwindows thread id:    " <<QThread::currentThread();

    m_thread = new QThread();
    m_thread->start();

    qDebug() << "m_timer thread before id: " <<m_timer->thread();

    //将m_timer定时器对象移到子线程
    m_timer->moveToThread(m_thread);

    qDebug() << "m_timer thread after id:  " <<m_timer->thread();

    //connect选用Qt::DirectConnection的方式表示：m_timer在子线程，m_myobject槽函数的执行也就相当于在子线程
    connect(m_timer,SIGNAL(timeout()),m_myobject,SLOT(slot_myObejctLoop()),Qt::DirectConnection);

    //connect选用Qt::QueuedConnection的方式是因为 myobject 的槽函数在执行时刻属于子线程，
    //该信号是在 myobject 此刻执行槽函数时发出的，所以发出的信号在子线程
    connect(m_myobject,SIGNAL(signal_myobject()),this,SLOT(slot_mainTest()),Qt::QueuedConnection);

    //connect选用Qt::QueuedConnection的方式是因为按键发出的信号在主线程，Qtimer定时器对象已经移到了子线程，这样操作属于不同线程
    //这样做的原因是定时器的开启和关闭必须与定时器对象所处线程一致，否则会报警告。
    connect(this,SIGNAL(signal_timerStart(int)),m_timer,SLOT(start(int)),Qt::QueuedConnection);
    connect(this,SIGNAL(signal_timerStop()),m_timer,SLOT(stop()),Qt::QueuedConnection);
}


MainWindow::~MainWindow()
{
    delete ui;
}

//主线程槽函数，等待被子线程信号触发
void MainWindow::slot_mainTest()
{
    qDebug() << "slot_mainTest :           " <<QThread::currentThread();
}

//快捷键按键转到槽
void MainWindow::on_pbn_start_clicked()
{
    qDebug() <<"button start";
    emit signal_timerStart(1000);
}

//快捷键按键转到槽
void MainWindow::on_pbn_stop_clicked()
{
    qDebug() <<"button stop";
    emit signal_timerStop();
}
