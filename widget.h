#ifndef WIDGET_H
#define WIDGET_H

#include "qabstractbutton.h"
#include <QWidget>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void iniUI();
public slots:
    void onButtonGroupClicked(QAbstractButton*btn);
private:
    Ui::Widget *ui;
    QVector<QVariant>vec;
};
#endif // WIDGET_H
