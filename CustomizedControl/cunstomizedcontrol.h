#ifndef CUNSTOMIZEDCONTROL_H
#define CUNSTOMIZEDCONTROL_H

#include <QWidget>

namespace Ui {
class CunstomizedControl;
}

class CunstomizedControl : public QWidget
{
    Q_OBJECT

public:
    explicit CunstomizedControl(QWidget *parent = nullptr);
    ~CunstomizedControl();
    void setNum(int num);
    int getNum();
private:
    Ui::CunstomizedControl *ui;
};

#endif // CUNSTOMIZEDCONTROL_H
