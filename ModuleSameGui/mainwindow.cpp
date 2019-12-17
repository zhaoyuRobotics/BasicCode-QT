#include "mainwindow.h"
#include "ui_mainwindow.h"

//主界面信号 -》 子界面槽函数  (先)
//子界面信号 -》 主界面槽函数  (后)


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_form1 = new Form(ui->tab);
    m_form2 = new Form(ui->tab_2);

    // 1.设置界面数据和成员变量数据

    FormGuiData tmp_StringForm1;
    tmp_StringForm1.label_1 = "这是界面1的label1";
    tmp_StringForm1.label_2 = "这是界面1的label2";

    FormGuiData tmp_StringForm2;
    tmp_StringForm2.label_1 = "这是界面2的label1";
    tmp_StringForm2.label_2 = "这是界面2的label2";

    m_form1->setGuiData(tmp_StringForm1);
    m_form2->setGuiData(tmp_StringForm2);
    m_form1->setMemberVariable("界面1成员变量");
    m_form2->setMemberVariable("界面2成员变量");

    // 2.设置控件背景图片

    m_form1->setGuiImage(":/image/image/led-green.png");
    m_form2->setGuiImage(":/image/image/led-red.png");

    // 3.获取界面信息

    tmp_StringForm1 = m_form1->getGuiData();
    tmp_StringForm2 = m_form2->getGuiData();
    qDebug() <<"界面1：" <<tmp_StringForm1.label_1<<" : "<<tmp_StringForm1.label_2<<endl;
    qDebug() <<"界面2："<< tmp_StringForm2.label_1<<" : "<<tmp_StringForm2.label_2<<endl;

    // 4.信号和槽
    connect(this,SIGNAL(signal_MainGuiSameSignal()),m_form1,SLOT(slot_receiveSameSignal()));
    connect(this,SIGNAL(signal_MainGuiSameSignal()),m_form2,SLOT(slot_receiveSameSignal()));
    connect(this,SIGNAL(signal_MainGuiDifferentSignal()),m_form1,SLOT(slot_receiveDifferentSignal()));
    connect(this,SIGNAL(signal_MainGuiDifferentSignal()),m_form2,SLOT(slot_receiveDifferentSignal()));
    connect(m_form1,SIGNAL(signal_1()),this,SLOT(slot_getSameSignalFromForm1()));
    connect(m_form2,SIGNAL(signal_1()),this,SLOT(slot_getSameSignalFromForm2()));
    connect(m_form1,SIGNAL(signal_2(QString)),this,SLOT(slot_getDifferentSignalFromForm1(QString)));
    connect(m_form2,SIGNAL(signal_2(QString)),this,SLOT(slot_getDifferentSignalFromForm2(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/** 交互性信号和槽 **/

void MainWindow::slot_getSameSignalFromForm1()
{
    ui->label->setText("接收到来自界面1的相同信号");
}

void MainWindow::slot_getDifferentSignalFromForm1(QString m_string)
{
    ui->label_3->setText(m_string);
}

void MainWindow::slot_getSameSignalFromForm2()
{
    ui->label_2->setText("接收到来自界面1的相同信号");
}

void MainWindow::slot_getDifferentSignalFromForm2(QString m_string)
{
    ui->label_4->setText(m_string);
}

/** 按键信号和槽 **/

void MainWindow::on_pushButton_clicked()
{
    emit signal_MainGuiSameSignal();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit signal_MainGuiDifferentSignal();
}
