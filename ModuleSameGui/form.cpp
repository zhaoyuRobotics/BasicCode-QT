#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}




Form::~Form()
{
    delete ui;
}





/**
 * @brief 设置界面数据
 *
 *
 *
 *
 */
void Form::setGuiData(FormGuiData m_string)
{
    ui->label_1->setText(m_string.label_1);
    ui->label_2->setText(m_string.label_2);
}




/**
 * @brief 设置界面主图片
 *
 *
 *
 *
 */
void Form::setGuiImage(QString m_dir)
{
    QPixmap pixmap(m_dir);
    ui->label_image->setPixmap(pixmap);
}





/**
 * @brief 设置成员变量数值
 *
 *
 *
 */
void Form::setMemberVariable(QString m_string)
{
    m_GuiName = m_string;
}





/**
 * @brief 返回界面数据
 *
 *
 *
 *
 */
FormGuiData Form::getGuiData()
{
    FormGuiData tmp_data;
    tmp_data.label_1 = ui->label_1->text();
    tmp_data.label_2 = ui->label_2->text();
    return tmp_data;
}





/**
 * @brief 发送相同信号
 *
 *
 *
 *
 */
void Form::slot_receiveSameSignal()
{
    emit signal_1();
}





/**
 * @brief 发送不同信号
 *
 *
 *
 *
 */
void Form::slot_receiveDifferentSignal()
{
    emit signal_2(m_GuiName);
}
