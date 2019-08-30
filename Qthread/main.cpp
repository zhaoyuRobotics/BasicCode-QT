#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    qDebug() << "main thread id:           " <<QThread::currentThread();
    MainWindow w;
    w.show();

    return a.exec();
}
