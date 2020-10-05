#include "iconbutton.h"
#include <qdebug.h>
#include <qpropertyanimation.h>
IconButton::IconButton(QString normal, QString push)
{
    normalImage=normal;
    pushImage=push;

    QPixmap pix;
    if(pix.load(normalImage))
    {
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize( pix.width(),pix.height()));
    }
    else
    {
        qDebug()<<"图片加载失败！";
        return;
    }
}

void IconButton::mousePressEvent(QMouseEvent* ev)
{
    QPixmap pix;
    if(pushImage=="")
        ;
    else if(pix.load(pushImage))
    {
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize( pix.width(),pix.height()));
    }
    else
    {
        qDebug()<<"图片加载失败！";
        return;
    }
    return QPushButton::mousePressEvent(ev);
}

void IconButton::mouseReleaseEvent(QMouseEvent* ev)
{
    QPixmap pix;
    if(pushImage=="")
        ;
    else if(pix.load(normalImage))
    {
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px;}");
        setIcon(pix);
        setIconSize(QSize( pix.width(),pix.height()));
    }
    else
    {
        qDebug()<<"图片加载失败！";
        return;
    }
    return QPushButton::mouseReleaseEvent(ev);
}

void IconButton::zoom1()
{
//    QPropertyAnimation * ani = new QPropertyAnimation(this,"size");
//    ani->setDuration(2000);
//    ani->setStartValue(QSize(this->width(),this->height()));
//    ani->setEndValue(QSize(this->width()-80,this->height()-80));
//    ani->start();
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}
void IconButton::zoom2()
{
//    QPropertyAnimation * ani = new QPropertyAnimation(this,"size");
//    ani->setDuration(2000);
//    ani->setStartValue(QSize(this->width()-80,this->height()-80));
//    ani->setEndValue(QSize(this->width(),this->height()));
//    ani->start();
    //创建动态对象
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //设置动画时间间隔
    animation->setDuration(200);

    //起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    //结束位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));

    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);

    //执行动画
    animation->start();
}

