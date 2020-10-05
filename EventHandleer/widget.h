#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void timerEvent(QTimerEvent *event);//定时器事件是窗口类中的事件

    int timer1;
    int timer2;

    bool eventFilter(QObject* ob, QEvent *ev);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
