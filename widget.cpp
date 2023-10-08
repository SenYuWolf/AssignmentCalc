#include "widget.h"
#include "./ui_widget.h"
#include <QButtonGroup>
#include <iostream>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    iniUI();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::iniUI()
{
    auto buttonGroup = new QButtonGroup(this);
    auto btnList = findChildren<QPushButton*>();
    for (auto btn:btnList)
    {
        buttonGroup->addButton(btn);
    }
    connect(buttonGroup,&QButtonGroup::buttonClicked,this,&Widget::onButtonGroupClicked);
    vec.resize(6);
}

void Widget::onButtonGroupClicked(QAbstractButton*btn)
{
    float val = ui->lineEdit->text().toFloat();
    QString name = btn->text();
    if(name >= "0" && name <= "9" || name == ".")
    {
        if(ui->lineEdit->text() == "0" && name != "."){
            ui->lineEdit->clear();
        }
        ui->lineEdit->insert(name);
    }
    else if(name == "C")
    {
        ui->lineEdit->clear();
        ui->lineEdit->insert("0");
    }
    else if(name == "=")
    {
        if(vec[0].isNull() || vec[1].isNull()){
            ui->lineEdit->setText("0");
        }
        else{
            vec[2] = val;
            if(vec[1] == "+"){
                vec[3] = vec[0].toFloat() + vec[2].toFloat();
            }
            else if(vec[1] == "-"){
                vec[3] = vec[0].toFloat() - vec[2].toFloat();
            }
            else if(vec[1] == "*"){
                vec[3] = vec[0].toFloat() * vec[2].toFloat();
            }
            else if(vec[1] == "/"){
                vec[3] = vec[0].toFloat() / vec[2].toFloat();
            }
            ui->lineEdit->setText(vec[3].toString());
            vec[0].clear();
            vec[1].clear();
            vec[2].clear();
            vec[3].clear();
        }
    }
    else if(name == "+")
    {
        vec[0] = val;
        vec[1] = "+";
        ui->lineEdit->clear();
    }
    else if(name == "-")
    {
        vec[0] = val;
        vec[1] = "-";
        ui->lineEdit->clear();
    }
    else if(name == "*")
    {
        vec[0] = val;
        vec[1] = "*";
        ui->lineEdit->clear();
    }
    else if(name == "/")
    {
        vec[0] = val;
        vec[1] = "/";
        ui->lineEdit->clear();
    }
    else if(name == "MR")
    {
        ui->lineEdit->setText(vec[4].toString());
    }
    else if(name == "MS")
    {
        vec[4] = ui->lineEdit->text();
    }
    else if(name == "+/-")
    {
        auto num = ui->lineEdit->text().toFloat();
        vec[5] = num * (-1);
        ui->lineEdit->setText(vec[5].toString());
    }
}
