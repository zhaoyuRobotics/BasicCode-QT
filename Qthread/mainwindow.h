#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include <myobject.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    //按键触发定时器开启，关闭。  原因：定时器的开启和关闭必须在同一个线程中，不然会有警告。
    void signal_timerStart(int);
    void signal_timerStop();

public slots:
    //槽函数，用于被子线程的信号出发
    void slot_mainTest();

private slots:
    //快捷按键转到槽
    void on_pbn_start_clicked();
    void on_pbn_stop_clicked();

private:
    Ui::MainWindow *ui;

    QThread *m_thread;
    QTimer  *m_timer;
    MyObject *m_myobject;
};

#endif // MAINWINDOW_H
