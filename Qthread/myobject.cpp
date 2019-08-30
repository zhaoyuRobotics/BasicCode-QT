#include "myobject.h"

MyObject::MyObject(QObject *parent) :
    QObject(parent)
{
    ;
}

void MyObject::slot_myObejctLoop()
{
    qDebug() << "----MyObject thread id:   " << QThread::currentThread();
    emit signal_myobject();
}
