#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),m_progressNum(0),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(QSize(300,300));

    label_Gif = new QLabel(this);
    label_Gif->setGeometry(70,70,130,130);

    label_Text = new QLabel(this);
    label_Text->setGeometry(100,200,80,80);
    label_Text->setStyleSheet("font: 20pt \"Ubuntu\"");
    label_Text->setAlignment(Qt::AlignHCenter);

    // 播放Loading动画
    m_Gif = new QMovie("/root/AuboProject/2.......QT_Demo/Gif/loading.gif");
    label_Gif->setMovie(m_Gif);
    m_Gif->start();

    // 定时器用于更新进度数字
    m_timer = new QTimer(this);
    connect(m_timer,SIGNAL(timeout()),this,SLOT(slot_Progress()));
    m_timer->start(100);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_Progress()
{
    if(m_progressNum > 100)
    {
        m_progressNum = 0;
    }else
    {
        m_progressNum++;
    }

    label_Text->setText(tr("%1 %").arg(m_progressNum));
}
