#ifndef WIDGETTEST2_H
#define WIDGETTEST2_H

#include <QWidget>

namespace Ui {
class widgettest2;
}

class widgettest2 : public QWidget
{
    Q_OBJECT

public:
    explicit widgettest2(QWidget *parent = 0);
    ~widgettest2();

private:
    Ui::widgettest2 *ui;
};

#endif // WIDGETTEST2_H
