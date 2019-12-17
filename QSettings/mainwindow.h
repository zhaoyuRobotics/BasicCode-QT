#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>
#include <QList>
#include <QDebug>


struct Login {
    QString userName;
    QString password;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void writeInfoToFile();

    void readInfoFromFile();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
