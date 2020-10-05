#include "coin.h"
#include "qdebug.h"
#include "qtimer.h"
#include "qpixmap.h"
Coin::Coin(QString btnImg)
{
    QPixmap pix;
    bool ret = pix.load(btnImg);
    if(!ret)
    {
        QString str = QString("图片 %1 加载失败").arg(btnImg);
        qDebug()<<str;
        return;
    }

    setFixedSize(pix.width(),pix.height());
    setStyleSheet("QPushButton{border:0px}");
    setIcon(pix);
    setIconSize(QSize(pix.width(),pix.height()));

    connect(&timer1,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str;
        str = QString(":/res/Coin000%1.png").arg(min++);

        pix.load(str);
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px}");
        setIcon(pix);
        setIconSize(QSize(pix.width(),pix.height()));
        if(min>max)
        {
            timer1.stop();
            isFlipping = false;
            min = 1;
            state = !state;
        }
    });

    connect(&timer2,&QTimer::timeout,[=](){
        QPixmap pix;
        QString str;

        str = QString(":/res/Coin000%1.png").arg(max--);
        pix.load(str);
        setFixedSize(pix.width(),pix.height());
        setStyleSheet("QPushButton{border:0px}");
        setIcon(pix);
        setIconSize(QSize(pix.width(),pix.height()));
        if(min>max)
        {
            timer2.stop();
            isFlipping = false;
            max = 8;
            state = !state;
        }
    });
}

void Coin::flipCoin()
{
    if(isFlipping==false)
    {
        isFlipping = true;
        if(state)
        {
            timer1.start(30);
        }
        else
        {
            timer2.start(30);
        }
    }
}

void Coin::mousePressEvent(QMouseEvent *e)
{
    if(frozen)
        return;
    else
        QPushButton::mousePressEvent(e);
}
