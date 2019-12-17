#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(loadFile()));

/** QListWidget显示某一路径下的.txt文件 **/

    //获取此路径下的所有目录
    QDir *dir = new QDir("/root/AuboProject/2.......QT_Demo/5.ViewList/config");
    //过滤掉后缀名部位txt的文件
    QStringList filter;
    filter<<"*.txt";
    dir->setNameFilters(filter);
    ui->listWidget->clear();
    //设置属性
    ui->listWidget->setViewMode(QListView::IconMode);
    ui->listWidget->setIconSize(QSize(80,80));
    ui->listWidget->setGridSize(QSize(150,100));
    //将文件显示在界面
    QStringList list = dir->entryList();
    QString string;
    for (int index = 0; index < list.size(); index++)
    {
        string = list.at(index);
        //添加（图标，名称）
//      ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr("/root/AuboProject/2.......QT_Demo/5.ViewList/resourse/file.jpg")), string));
//      ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr("./../resourse/file.jpg")), string));
        ui->listWidget->addItem(new QListWidgetItem(QIcon(QObject::tr(":/resourse/file.jpg")), string));
    }





/** 利用QtreeWidget树型显示某一路径 **/
    m_model = new QFileSystemModel;
    m_model->setRootPath("/root");
    ui->treeView->setModel(m_model);
    ui->treeView->setRootIndex(m_model->index("/root"));




/** 限制lineEdit输入字符的数量为5 **/
    ui->lineEdit->setMaxLength(5);

}

MainWindow::~MainWindow()
{
    delete ui;
}






//获取被选中的文件item的text名称
void MainWindow::loadFile()
{
    qDebug() << ui->listWidget->currentItem()->text();
}
