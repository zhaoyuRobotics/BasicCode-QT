#include "widgettest.h"
#include "widgettest2.h"
#include <QApplication>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    WidgetTest w;
    w.show();

//    QWidget *widget_1 = new QWidget();
//    widget_1->setWindowTitle(QObject::tr("test"));
//    widget_1->setFixedSize(800,800);
//    QLabel  *label_1 = new QLabel(widget_1);
//    label_1->setText("我是第1个label");
//    label_1->setGeometry(10,10,200,15);
//    QLabel  *label_2 = new QLabel(widget_1);
//    label_2->setText("我是第2个label");
//    label_2->setGeometry(600,780,200,15);
//    widget_1->show();

    int ret = a.exec();

//    delete widget_1;

    return ret;
}
