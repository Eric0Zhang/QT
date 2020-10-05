#include "mylabel.h"
#include <QDebug>
#include <QMouseEvent>
myLabel::myLabel(QWidget *parent) : QLabel(parent)
{
    setMouseTracking(true);//打开鼠标追踪，则不按下按钮也能触发移动事件
}

void myLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"Mouse left!";
}
void myLabel::enterEvent(QEvent *event)
{
    qDebug()<<"Mouse entered!";
}

bool myLabel::event(QEvent *ev)
{
    if(ev->type() == QEvent::MouseMove)
    {
        //return true;//返回true不下发，即拦截该事件,这时mousePressEvent函数不再响应
    }
    else if(ev->type() == QEvent::MouseButtonRelease)
    {
        //这里使用静态类型转换，从事件指针获得鼠标事件
        QMouseEvent * mev = static_cast<QMouseEvent *>(ev);
        if(mev->button() == Qt::LeftButton)
        {
            QString string = QString("event captured mouse released at(%1,%2)=global(%3,%4)").arg(mev->x()).arg(mev->y()).arg(mev->globalX()).arg(mev->globalY());
            qDebug()<<string;
        }
        return true;
    }

    return QLabel::event(ev);//默认交给父类处理
}
void myLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"mouse pressed!";
}
void myLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        QString string = QString("mouse released at(%1,%2)=global(%3,%4)").arg(ev->x()).arg(ev->y()).arg(ev->globalX()).arg(ev->globalY());
        qDebug()<<string;
    }
}
void myLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //if(ev->buttons() & Qt::LeftButton)//判断左键是否按下要用buttons，因为有可能同时几个都按下，状态中有好几个都是有效。所以位与来区分。
    //if(ev->button() == Qt::LeftButton)
    {
        qDebug()<<"Left mouse moving!";
    }
}
