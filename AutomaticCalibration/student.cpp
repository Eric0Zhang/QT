#include "student.h"
#include <QDebug>
Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"请老师吃饭！";
}


void Student::treat(QString food)
{

    qDebug()<<"请老师吃"<<food<<food.toUtf8().data();//先转UTF8字节数组，再转成字符串，这样就不带小数点
}
