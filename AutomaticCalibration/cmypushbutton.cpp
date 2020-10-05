#include "cmypushbutton.h"
#include <QDebug>
CMyPushButton::CMyPushButton(QPushButton *parent) : QPushButton(parent)
{
    qDebug()<<"我的按钮类构造";
}

CMyPushButton::~CMyPushButton()
{
    qDebug()<<"我的按钮类析构";
}
