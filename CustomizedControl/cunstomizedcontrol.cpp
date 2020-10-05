#include "cunstomizedcontrol.h"
#include "ui_cunstomizedcontrol.h"

CunstomizedControl::CunstomizedControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CunstomizedControl)
{
    ui->setupUi(this);
    void (QSpinBox:: * spinSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox,spinSignal,ui->horizontalSlider,&QSlider::setValue);
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

void CunstomizedControl::setNum(int num)
{
    this->ui->spinBox->setValue(num);
}
int CunstomizedControl::getNum()
{
    return this->ui->spinBox->value();
}

CunstomizedControl::~CunstomizedControl()
{
    delete ui;
}
