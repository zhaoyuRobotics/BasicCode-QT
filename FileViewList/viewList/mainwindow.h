#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QDebug>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MyFileSystemModel : public QFileSystemModel
{ public: //第1列显示名称，其他几列都屏蔽掉
    int columnCount(const QModelIndex &parent) const { return 1; }
};



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void loadFile();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_model;
};

#endif // MAINWINDOW_H
