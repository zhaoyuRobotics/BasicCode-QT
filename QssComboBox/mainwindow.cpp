#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStyledItemDelegate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->setMaxVisibleItems(5);
    QStyledItemDelegate* itemDelegate = new QStyledItemDelegate();
    ui->comboBox->setItemDelegate(itemDelegate);
}

MainWindow::~MainWindow()
{
    delete ui;
}


