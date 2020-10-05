#include "widget.h"
#include <QDebug>
#include <QPushButton>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->tch = new Teacher(this);//指定父类可以自动释放
    this->std = new Student(this);
    qDebug()<<"父类WIDGET类构造";
//    QPushButton * myBtn = new QPushButton (this);
//    QPushButton * myBtn2 = new QPushButton (this);
//    myBtn->move(50,200);
//    myBtn2->move(150,200);
//    myBtn->resize(100,50);
//    myBtn2->resize(100,50);
//    myBtn->setText("mutable");
//    myBtn2->setText("direct");


//    int m = 10;
//    //mutable关键字是的lambd的内部只能修改传入参数的拷贝
//    connect(myBtn,&QPushButton::clicked,this,[&] () { m = 100 + 10; qDebug() << m; });

//    connect(myBtn2,&QPushButton::clicked,this,[=] ()  { qDebug() << m; emit tch->hungry("宫保鸡丁",10); });
//    //可以看出，使用lambda表达式可以匹配这种调用函数对象或函数指针的场合，然后由于信号连接检查参数列表，clicked只能匹配一个传入参数，
//    //而这种hungry两个参数的槽函数，clicked是没法直接调用的，可以采用lambda

//    qDebug() << m;
}

Widget::~Widget()
{
    qDebug()<<"父类WIDGET类析构";
}

void Widget::ClassOver()
{
    emit tch->hungry("红烧肉",2);//也可以直接调用，也可以用emit
    emit tch->hungry();//也可以直接调用，也可以用emit
}

