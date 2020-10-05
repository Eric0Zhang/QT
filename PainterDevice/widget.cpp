#include "widget.h"
#include "ui_widget.h"
#include <QPixmap>
#include <QPainter>
#include <QImage>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPixmap px(300,300);
    px.fill(Qt::white);
    QPainter painter(&px);//向pixmap设备绘图
    painter.setPen(QPen(Qt::green));
    painter.drawEllipse(150,150,100,100);
    px.save("Pixmap.png");
}

Widget::~Widget()
{
    delete ui;
}

