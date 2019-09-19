#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "QDebug"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


signals:
    void signal_MainGuiSameSignal();
    void signal_MainGuiDifferentSignal();

public slots:
    void slot_getSameSignalFromForm1();
    void slot_getDifferentSignalFromForm1(QString m_string);

    void slot_getSameSignalFromForm2();
    void slot_getDifferentSignalFromForm2(QString m_string);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Form *m_form1;
    Form *m_form2;
};

#endif // MAINWINDOW_H
