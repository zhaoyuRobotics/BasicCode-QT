#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->writeInfoToFile();
    this->readInfoFromFile();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeInfoToFile()
{
    QSettings *setting = new QSettings("/root/AuboProject/2.......QT_Demo/7.setting/setting/config/test.ini",QSettings::IniFormat);

    setting->beginGroup("SerialPort");
    setting->setValue("port",115200);
    setting->endGroup();

    setting->beginGroup("windows");
    setting->setValue("color","#ffffff");
    setting->setValue("isdisplay",true);
    setting->beginWriteArray("list");
    for (int i = 0; i < 5; ++i) {
        setting->setArrayIndex(i);
        setting->setValue("number", i);
    }
    setting->endArray();
    setting->endGroup();


    delete setting;
}

void MainWindow::readInfoFromFile()
{
    QSettings *setting = new QSettings("/root/AuboProject/2.......QT_Demo/7.setting/setting/config/test.ini",QSettings::IniFormat);

    setting->beginGroup("SerialPort");
    int port_value = setting->value("port").toInt();
    setting->endGroup();
    qDebug() << port_value <<endl;

    setting->beginGroup("windows");
    QString color = setting->value("color").toString();
    QString isdisplay = setting->value("isdisplay").toString();
    qDebug() << color <<endl;
    qDebug() << isdisplay <<endl;

    int array_value = 0;
    int size = setting->beginReadArray("list");
    for (int i = 0; i < size; ++i) {
        setting->setArrayIndex(i);
        array_value =  setting->value("number").toInt();
        qDebug() << array_value <<endl;
    }
    setting->endArray();
    setting->endGroup();

    delete setting;
}
