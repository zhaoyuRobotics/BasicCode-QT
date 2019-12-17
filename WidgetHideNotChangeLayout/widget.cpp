#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

/**
 * 解决的问题：布局后的GroupBox在隐藏后，布局发生改变(相当于控件不在布局当中)
 *
 * 解决的方法：创建一个与GroupBox一样大小的窗体，在GroupBox隐藏后，让新创建的窗体填充进去继续布局
 *
 *
**/

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    windows = new QWidget(this);
    windows->setFixedSize(150,150);

    //设置样式表背景
    windows->setStyleSheet(QString::fromUtf8("background-color: rgb(24 ,116 ,205)"));

    //创建的新Widget加入布局后不需要show（）就可以显示出来
    ui->verticalLayout->addWidget(windows);
    //新窗口一开始不需要显示
    windows->hide();
}



Widget::~Widget()
{
    delete ui;
}




void Widget::on_pushButton_5_clicked()
{
    ui->groupBox->show();
    windows->hide();
}







void Widget::on_pushButton_clicked()
{
    ui->groupBox->hide();
    windows->show();
}
