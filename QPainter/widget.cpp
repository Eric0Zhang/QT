#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    posh = 10;
    ui->setupUi(this);
    connect(ui->hs,&QAbstractSlider::sliderMoved,[=](int a){
        posh = 4*a;
        //this->repaint();
        update();
    });
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent * pev)
{
    QPainter painter(this);
    QPen pen(QColor(255,0,0));
    pen.setWidth(1);
    pen.setStyle(Qt::SolidLine);

    QBrush br(Qt::magenta);
    br.setStyle(Qt::Dense4Pattern);
    painter.setPen(pen);
    painter.setBrush(br);

    painter.drawLine(QPoint(0,0),QPoint(200,200));
    painter.drawEllipse(QPoint(200,200),80,80);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawEllipse(QPoint(360,360),80,80);
    painter.setRenderHint(QPainter::HighQualityAntialiasing,true);
    painter.drawEllipse(QPoint(540,540),80,80);

    painter.translate(540,540);
    painter.drawPie(QRect(0,0,80,80),10,600);
    painter.translate(-540,-540);
    painter.drawPixmap(posh,100,QPixmap(":/Image/Luffy.png"));
}
