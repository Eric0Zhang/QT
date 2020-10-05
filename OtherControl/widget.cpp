#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->scroll,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->tabbtn,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(1);
    });
    connect(ui->tool,&QPushButton::clicked,[=](){
       ui->stackedWidget->setCurrentIndex(2);
    });
    ui->stackedWidget->setCurrentIndex(0);

    ui->combo->addItem("宝马");
    ui->combo->addItem("奔驰");
    ui->combo->addItem("拖拉机");

    connect(ui->top,&QPushButton::clicked,[=](){
        ui->combo->setCurrentIndex(1);
    });
    connect(ui->mid,&QPushButton::clicked,[=](){
        ui->combo->setCurrentIndex(0);
    });
    connect(ui->low,&QPushButton::clicked,[=](){
        ui->combo->setCurrentIndex(2);
    });

    ui->label->setPixmap(QPixmap(":/Image/OnePiece.png"));
    QMovie *movie = new QMovie(":/Image/mario.gif");
    ui->labelMovie->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

