#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer1 = startTimer(1000);
    timer2 = startTimer(2000);

    //定时器对象使用更方便
    QTimer *timer3 = new QTimer(this);
    timer3->start(500);
    connect(timer3,&QTimer::timeout,[=](){
        static int num = 1;
        ui->label_4->setText(QString::number(num++));
    });

//    connect(ui->pBtnStop,&QPushButton::clicked,timer3,&QTimer::stop);
    connect(ui->pBtnStop,&QPushButton::clicked,[=](){
        if(ui->pBtnStop->text() == "暂停timer3")
        {
            timer3->stop();
            ui->pBtnStop->setText("继续timer3");
        }
        else
        {
            timer3->start();
            ui->pBtnStop->setText("暂停timer3");
        }
    });
    //给label安装事件过滤器
    ui->label->installEventFilter(this);

}

Widget::~Widget()
{
    delete ui;
}

bool Widget::eventFilter(QObject* ob, QEvent *ev)
{
    if(ob==ui->label)
    {
        if(ev->type()==QEvent::MouseMove)
        {
            return true;// 返回true则拦截不下发。
        }
    }

    return QWidget::eventFilter(ob,ev);
}

void Widget::timerEvent(QTimerEvent *event)
{
    static int num = 1;
    static int num2 = 1;
    if(event->timerId() == timer1)
        ui->label_2->setText(QString::number(num++));
    else if(event->timerId()==timer2)
        ui->label_3->setText(QString::number(num2++));
}
