#include "widgettest.h"
#include "widgettest2.h"
#include "ui_widget_Interface.h"

WidgetTest::WidgetTest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WidgetTest)
{
    ui->setupUi(this);
    ui->tabWidget->addTab(new widgettest2(this),"Widget");
}

WidgetTest::~WidgetTest()
{
    delete ui;
}
