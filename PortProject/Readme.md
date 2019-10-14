### 此工程实现串口的接收和发送功能, 但是判断整个一帧数据是否完善需要自己根据协议去添加  ###  

### 总结: ###  


1.getSerialPortNames()           //获取串口号
  用途:将获取到的端口号写在串口的COMBO BOX控件上,这个端口号要在配置串口时需要,如下:
  QString comname=ui->serialport->currentText();

  if(info.portName()==comname)
  {

  } 
  

2.SetPortConfig()               //配置串口函数
  用途:将串口的端口号,波特率,数据位,停止位,校验,流控,以及以可读可写的方式打开  
  

3.sendData()                    //发送数据
  用途:将字符串(12345或者hello在plain text edit控件上都是字符串) 追加在QBytearray上发送出去.程序中发送方式有两种,一种是以字符串形式发送,一种是以十六进制发送,其实这两种方式可以归为一种:
  第一种:发送'A'   存储在QBytearray中的形式就是:0100 0001(41).
  第二种:发送'A'   首相讲'A'转换为0100 0001,然后存储在QBytearray中.  
  
  
4.receiveData()                 //接收数据
  用途:将接收到的数据显示到界面上,显示分为两种:
  1.显示接收到的数据的十六进制:
    核心:     
        //十六进制的数字直接原模原样放到字符串中,显示的字符串是十六进制数字
        for (int i = 0; i < showdata.length(); i++)
        {
            qint8   outChar = showdata[i];
            QString str = QString("%1").arg(outChar&0xFF, 2, 16, QLatin1Char('0'))+" ";
            show+= str.toUpper();
        }
  2.显示接收到的数据对应的ascall字符  
  
  
5.本程序串口接收用的是信号和曹:
  核心:
      connect(my_serialport,SIGNAL(readyRead()),this,SLOT(receiveData()));


6.示例中 要发字符串就按照输入的字符对应的AScall码发送， 要发送数字就选择界面中的Hex，此模式试讲输入字符串转换为一样的数字发送

