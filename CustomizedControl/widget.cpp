#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->getValue,&QPushButton::clicked,[=](){
        qDebug()<<"Current number is: "<<ui->myWidget->getNum();
    });
    connect(ui->set2Half,&QPushButton::clicked,[=](){
        ui->myWidget->setNum(50);
    });
}

Widget::~Widget()
{
    delete ui;
}

