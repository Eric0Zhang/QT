#ifndef CMYPUSHBUTTON_H
#define CMYPUSHBUTTON_H

#include <QPushButton>

class CMyPushButton : public QPushButton
{
    Q_OBJECT
public:
    explicit CMyPushButton(QPushButton *parent = nullptr);
    ~CMyPushButton();
signals:

};

#endif // CMYPUSHBUTTON_H
