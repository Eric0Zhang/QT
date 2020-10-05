#ifndef ICONBUTTON_H
#define ICONBUTTON_H

#include <qpushbutton.h>

class IconButton : public QPushButton
{
    Q_OBJECT
public:
    IconButton(QString normal, QString push = "");
    QString normalImage;
    QString pushImage;

    void zoom1();
    void zoom2();
    void mousePressEvent(QMouseEvent* ev);
    void mouseReleaseEvent(QMouseEvent* ev);
signals:

};

#endif // ICONBUTTON_H
