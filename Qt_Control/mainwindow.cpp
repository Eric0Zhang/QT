#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rbMan->setChecked(true);
    ui->rbMarried->setChecked(true);
    connect(ui->rbMan,&QRadioButton::clicked,[=](){
        sex=1;
        qDebug()<<"you're a man.";
    });
    connect(ui->rbWoman,&QRadioButton::clicked,[=](){
        sex=0;
        qDebug()<<"you're a woman.";
    });
    connect(ui->rbMarried,&QRadioButton::clicked,[=](){
        married=1;
        qDebug()<<"you're married.";
    });
    connect(ui->rbUnmarried,&QRadioButton::clicked,[=](){
        married=0;
        qDebug()<<"you're unmarried.";
    });
    //注意这里将stateChanged的参数state传入到了lambda表达式中
    connect(ui->cbHaochi,&QCheckBox::stateChanged,[=](int state){
        qDebug()<<"Haochi state: "<<state;
    });

    //QStringList就是用QList容器中放置QString，即QList<QString>，是类似C++模板的封装
    QStringList list;
    list<<"秋风词"<<""<<"秋风清，秋月明，"<<"落叶相见知何日？此时此夜难为情！"\
       <<"入我相思门，知我相思苦，"<<"长相思兮长相忆，短相思兮无穷极，"\
        <<"早知如此绊人心，何如当初莫相识。";
    ui->listWidget->addItems(list);
    int num = ui->listWidget->count();  //获取列表项的总数目
    //ui->listWidget->setFocus(); //将光标设置到列表框上，若注释该语句，则删除时，要手动将焦点设置到列表框，即点击列表项
    for(int i=0;i<num;i++)
    {   //逐个获取列表项的指针，并删除
        ui->listWidget->item(i)->setTextAlignment(Qt::AlignHCenter);
        ui->listWidget->item(i)->setFont(QFont("微软雅黑",18));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

