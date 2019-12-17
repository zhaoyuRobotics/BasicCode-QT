#include "port.h"
#include "ui_port.h"

// 注意：windows和linux用的串口名字不同（windows用info.portName()   linux用info.systemLocation()）
// 注意：打开串口成功时必须保证数据位选择正确，一般为8
#define windows 1
#define linux   0

Port::Port(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Port)
{
    ui->setupUi(this);
    //私有变量初始化
    isopen = false;
    isHexS = false;
    isHexR = false;

    my_serialport = new QSerialPort();
    getSerialPortNames();

    connect(my_serialport,SIGNAL(readyRead()),this,SLOT(receiveData()));
}

Port::~Port()
{
    delete ui;
    delete my_serialport;
}


//获取串口号
void Port::getSerialPortNames()
{
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name : " << info.portName();
        qDebug() << "System Location: " << info.systemLocation();
        ui->serialport->addItem(info.portName());
    }
}


//配置串口
void Port::SetPortConfig()
{
    //设置串口号
        QString comname=ui->serialport->currentText();
        foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
        {
            if(info.portName()==comname)
            {
                if(windows)
                {
                     my_serialport->setPortName(info.systemLocation());
                }

                if(linux)
                {
                    my_serialport->setPortName(comname);
                }
            }
        }

    //设置波特率
        qint32 baudrate_index = ui->comboBox_fre->currentIndex();
        switch (baudrate_index) {
        case 0:
            my_serialport->setBaudRate(QSerialPort::Baud1200,QSerialPort::AllDirections);
            break;
        case 1:
            my_serialport->setBaudRate(QSerialPort::Baud2400,QSerialPort::AllDirections);
            break;
        case 2:
            my_serialport->setBaudRate(QSerialPort::Baud4800,QSerialPort::AllDirections);
            break;
        case 3:
            my_serialport->setBaudRate(QSerialPort::Baud9600,QSerialPort::AllDirections);
            break;
        case 4:
            my_serialport->setBaudRate(QSerialPort::Baud19200,QSerialPort::AllDirections);
            break;
        case 5:
            my_serialport->setBaudRate(QSerialPort::Baud38400,QSerialPort::AllDirections);
            break;
        case 6:
            my_serialport->setBaudRate(QSerialPort::Baud57600,QSerialPort::AllDirections);
            break;
        case 7:
            my_serialport->setBaudRate(QSerialPort::Baud115200,QSerialPort::AllDirections);
            break;
        default:
            my_serialport->setBaudRate(QSerialPort::UnknownBaud,QSerialPort::AllDirections);
            break;
        }

    //设置数据位
        qint32 databits_index=ui->comboBox_data->currentIndex();
        switch (databits_index) {
        case 0:
            my_serialport->setDataBits(QSerialPort::Data5);
            break;
        case 1:
            my_serialport->setDataBits(QSerialPort::Data6);
            break;
        case 2:
            my_serialport->setDataBits(QSerialPort::Data7);
            break;
        case 3:
            my_serialport->setDataBits(QSerialPort::Data8);
            break;
        default:
            my_serialport->setDataBits(QSerialPort::UnknownDataBits);
            break;
        }

    //设置校验位
        qint32 parity_index=ui->comboBox_check->currentIndex();
        switch (parity_index) {
        case 0:
            my_serialport->setParity(QSerialPort::NoParity);
            break;
        case 1:
            my_serialport->setParity(QSerialPort::OddParity);
            break;
        case 2:
            my_serialport->setParity(QSerialPort::EvenParity);
            break;
        default:
            my_serialport->setParity(QSerialPort::UnknownParity);
            break;
        }

    //设置停止位
        qint32 stopbit_index=ui->comboBox_stop->currentIndex();
        switch (stopbit_index) {
        case 0:
            my_serialport->setStopBits(QSerialPort::OneStop);
            break;
        case 1:
            my_serialport->setStopBits(QSerialPort::TwoStop);
            break;
        default:
            my_serialport->setStopBits(QSerialPort::UnknownStopBits);
            break;
        }

    //流控:无
        my_serialport->setFlowControl(QSerialPort::NoFlowControl);

    //打开串口
        if(ui->pb_open_serial->text()=="打开串口")
        {
            bool com=my_serialport->open(QIODevice::ReadWrite); //打开串口并选择读写模式
            if(com)
            {
                ui->statusBar->showMessage("串口打开成功",3000);
                isopen=true;
                ui->pb_open_serial->setText("关闭串口");
            }
            else
            {

                qDebug()<<"串口打开失败";
                //this->setStatusTip("串口打开失败");
                ui->statusBar->showMessage("串口打开失败",3000);
                isopen=false;
            }
        }
        else
        {

           if(my_serialport->isOpen())
            {
               my_serialport->close();
            }
            ui->pb_open_serial->setText("打开串口");
            ui->statusBar->showMessage("serial port is closed",3000);
        }
}


//发送函数
void Port::sendData()
{
    if(isopen)
    {
        if(!ui->text_senddata->toPlainText().isEmpty())
        {
            isHexS=ui->isHexS->isChecked();
            QString sendstr=ui->text_senddata->toPlainText();
            QByteArray sdata;
            QByteArray tmp_dataHex;

            if(isHexS)
            {
                tmp_dataHex.append(sendstr);
                // 按照输入的数字发送
                sdata.append(tmp_dataHex.toInt());
            }
            else
            {
                // 按照字符对应的Ascall码十六进制发送
                sdata.append(sendstr);
            }

            my_serialport->write(sdata,sdata.length());
            ui->statusBar->showMessage("send success",3000);
        }
        else
        {
            ui->statusBar->showMessage("请输入要发送的数据",3000);
        }
    }
    else
    {
        ui->statusBar->showMessage("请先打开串口",3000);
    }
}


//接收数据
void Port::receiveData()
{
    QByteArray showdata=my_serialport->readAll();
    QString    show="";
    isHexR=ui->isHexR->isChecked();
    if(isHexR)
    {
        //十六进制的数字直接原模原样放到字符串中,显示的字符串是十六进制数字
        for (int i = 0; i < showdata.length(); i++)
        {
            qint8   outChar = showdata[i];
            QString str = QString("%1").arg(outChar&0xFF, 2, 16, QLatin1Char('0'))+" ";  // 十六进制，前面自动补0
            show+= str.toUpper();
        }
    }
    //十六进制对应的ascall值
    else
    {
        show+=QString(showdata);
    }

    qDebug() <<"接收： "<< show <<endl;
    ui->textBrowser->setText(ui->textBrowser->toPlainText()+show);
}


//打开/关闭串口按钮
void Port::on_pb_open_serial_clicked()
{
    SetPortConfig();
}

//发送按钮
void Port::on_pb_sendData_clicked()
{
    sendData();
}
