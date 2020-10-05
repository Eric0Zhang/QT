#include "widget.h"

#include <QApplication>
#include <QPushButton>
#include "cmypushbutton.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    CMyPushButton *mypb = new CMyPushButton();//继承自QObject的类，会自动释放内存
    QPushButton *pushButton = new QPushButton("早期虫儿",&w);
    mypb->setText("MyPushButton下课");
    mypb->setParent(&w);
    mypb->resize(150,50);
    mypb->move(200,300);
    w.resize(1000,600);
    pushButton->move(200,100);
    pushButton->resize(100,50);

    //w.connect(mypb,&CMyPushButton::clicked,&w,&Widget::close);//这里调用了系统自带的槽函数close
    //w.connect(mypb,&CMyPushButton::clicked,w.tch,&Teacher::hungry);//这里用信号调用了另一个信号作为槽函数
    w.connect(mypb,&CMyPushButton::clicked,&w,&Widget::ClassOver);//这里调用了自定义的槽函数ClassOver
    //w.disconnect(mypb,&CMyPushButton::clicked,&w,&Widget::ClassOver);//这里接触了信号和槽的连接

    QPushButton * myBtn = new QPushButton ("mutable",&w);
    QPushButton * myBtn2 = new QPushButton ("direct",&w);
//    myBtn->setParent(&w);
//    myBtn2->setParent(&w);
    myBtn->move(50,200);
    myBtn2->move(150,200);
    myBtn->resize(100,50);
    myBtn2->resize(100,50);

    int m = 10;
    //mutable关键字是的lambda的内部只能修改传入参数的拷贝
    w.connect(myBtn,&QPushButton::clicked,&w,[&](){ m = 100 + 10; qDebug() << m; });//?/???值为何不变

    w.connect(myBtn2,&QPushButton::clicked,&w,[=](){ qDebug() << m;/* emit w.tch->hungry("宫保鸡丁",10); */});
    //可以看出，使用lambda表达式可以匹配这种调用函数对象或函数指针的场合，然后由于信号连接检查参数列表，clicked只能匹配一个传入参数，
    //而这种hungry两个参数的槽函数，clicked是没法直接调用的，可以采用lambda

    qDebug() << m;

    w.setWindowTitle("非常方便啊");
    w.setFixedSize(600,400);
//    pushButton->setText("生命在于运动");
//    pushButton->setParent(&w);
    w.show();

    //由于信号和槽发生了重载，所以必须明确函数指针的类型，然后connect函数指针
    void (Student::*pslot)(QString) = &Student::treat;
    void (Teacher::*psignal)(QString,int) = &Teacher::hungry;
    w.connect(w.tch,psignal,w.std,pslot);

    void (Student::*pslot2)() = &Student::treat;
    void (Teacher::*psignal2)() = &Teacher::hungry;
    w.connect(w.tch,psignal2,w.std,pslot2);

    [=]()
    {
        mypb->setText("下课了！");
    }();//花括号前面的都是lambda的声明，最后加一个()，实现函数调用 lambda通常配合STL的算法（需要调用函数对象）使用

    return a.exec();//消息循环
}
