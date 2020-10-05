#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->table->setColumnCount(3);
    ui->table->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");
    ui->table->setRowCount(5);
    ui->table->setColumnWidth(0,190);
    ui->table->setColumnWidth(1,190);
    ui->table->setColumnWidth(2,190);

    //ui->table->setItem(0,0, new QTableWidgetItem("亚瑟"));//用new设置匿名对象
    QStringList name;
    name<<"亚瑟"<<"赵云"<<"张飞"<<"关羽"<<"花木兰";
    QList<QString> sex; //QLIST<QString>等价于QStringList 就是一个模板容器
    sex<<"男"<<"男"<<"男"<<"男"<<"女";
    QStringList age;
    age<<QString::number(28)<<"29"<<"40"<<"41"<<"25";//注意Nubmer可以把数字变成QString
    for(int i=0;i<5;i++)
    {
        int col=0;
        ui->table->setRowHeight(i,60);
        ui->table->setItem(i,col++, new QTableWidgetItem(name.at(i)));//用new设置匿名对象的指针
        ui->table->setItem(i,col++, new QTableWidgetItem(sex[i]));//也可以用中括号来索引,但是中括号越界的话，软件崩溃，而at会报一个异常
        ui->table->setItem(i,col++, new QTableWidgetItem(age.at(i)));
    }
    for(int i=0;i<5;i++)
        for(int j=0;j<3;j++)
            ui->table->item(i,j)->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);

}

MainWindow::~MainWindow()
{
    delete ui;
}

