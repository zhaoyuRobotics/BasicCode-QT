#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QTimer>
#include <QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slot_Progress();

private:
    Ui::MainWindow *ui;
    QLabel *label_Gif;
    QLabel *label_Text;

    QMovie *m_Gif;
    QTimer *m_timer;
    quint8  m_progressNum;
};

#endif // MAINWINDOW_H
