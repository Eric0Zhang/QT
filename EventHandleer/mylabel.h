#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>


class myLabel : public QLabel
{
    Q_OBJECT
public:
    explicit myLabel(QWidget *parent = nullptr);
    void leaveEvent(QEvent *event);
    void enterEvent(QEvent *event);
    bool event(QEvent *ev);//重写事件分发器，拦截一些事件
    void mouseMoveEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);
    void mouseReleaseEvent(QMouseEvent *ev);

signals:

};

#endif // MYLABEL_H
