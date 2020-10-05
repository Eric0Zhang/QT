#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include <qtimer.h>
class Coin : public QPushButton
{
    Q_OBJECT
public:
    //explicit Coin(QWidget *parent = nullptr);
    Coin(QString btnImg);
    int pX;
    int pY;
    int state;//1-金币 0-银币
    void flipCoin();
    QTimer timer1,timer2;
    bool isFlipping = false;//金币正在翻转，不能响应点击
    int min = 1;
    int max = 8;
    bool frozen = 0;

    void mousePressEvent(QMouseEvent *e);

signals:

};

#endif // COIN_H
