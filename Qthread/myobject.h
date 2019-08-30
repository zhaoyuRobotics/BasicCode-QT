#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <unistd.h>

class MyObject : public QObject
{
    Q_OBJECT
public:
    explicit MyObject(QObject *parent = 0);

signals:
    //用于触发主线程槽函数
    void signal_myobject();

public slots:
    //该槽函数将依托定时器移对象移动到子线程，并且信号和槽的连接方式为Qt::DirectConnection，因此槽函数也就在子线程中执行
    void slot_myObejctLoop();
};

#endif // MYOBJECT_H
