#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

struct FormGuiData{
    QString label_1;
    QString label_2;
};

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

    void setGuiData(FormGuiData m_string);

    void setGuiImage(QString m_dir);

    void setMemberVariable(QString m_string);

    FormGuiData getGuiData();

signals:
    void signal_1();
    void signal_2(QString m_string);

public slots:

    void slot_receiveSameSignal();
    void slot_receiveDifferentSignal();

private:
    Ui::Form *ui;

    QString m_GuiName;
};

#endif // FORM_H
