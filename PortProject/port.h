#ifndef PORT_H
#define PORT_H

#include <QMainWindow>
#include <QTimer>
#include <QDebug>
#include <QIODevice>
#include <QSerialPortInfo>
#include <QSerialPort>

namespace Ui {
class Port;
}

class Port : public QMainWindow
{
    Q_OBJECT

public:
    explicit Port(QWidget *parent = 0);
    ~Port();

    void getSerialPortNames();
    void SetPortConfig();
    void sendData();

private slots:
    void receiveData();
    void on_pb_open_serial_clicked();
    void on_pb_sendData_clicked();

private:
    Ui::Port *ui;
    bool isopen;
    bool isHexS;
    bool isHexR;

    QTimer *m_time;
    QSerialPort *my_serialport;
};

#endif // PORT_H
