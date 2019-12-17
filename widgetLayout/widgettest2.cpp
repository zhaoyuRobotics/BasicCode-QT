#include "widgettest2.h"
#include "ui_widgettest_interface2.h"

widgettest2::widgettest2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::widgettest2)
{
    ui->setupUi(this);
}

widgettest2::~widgettest2()
{
    delete ui;
}
