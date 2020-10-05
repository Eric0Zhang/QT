#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QStringList直接调用构造函数，创造了一个“匿名对象”，直接用匿名对象调用<<操作符进行格式化。
    ui->tree->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");

    QTreeWidgetItem *item1 = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *item2 = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *item3 = new QTreeWidgetItem(QStringList()<<"智力");
    ui->tree->addTopLevelItem(item1);
    ui->tree->addTopLevelItem(item2);
    ui->tree->addTopLevelItem(item3);
    QTreeWidgetItem *l1 = new QTreeWidgetItem(QStringList()<< "刚被猪" << "前排坦克，能在吸收伤害的同时造成可观的范围输出");
    QTreeWidgetItem *l2 = new QTreeWidgetItem(QStringList()<< "船长" << "前排坦克，能肉能输出能控场的全能英雄");
    QTreeWidgetItem *m1 = new QTreeWidgetItem(QStringList()<< "月骑" << "中排物理输出，可以使用分裂利刃攻击多个目标");
    QTreeWidgetItem *m2 = new QTreeWidgetItem(QStringList()<< "小鱼人" << "前排战士，擅长偷取敌人的属性来增强自身战力");
    QTreeWidgetItem *z1 = new QTreeWidgetItem(QStringList()<< "死灵法师" << "前排法师坦克，魔法抗性较高，拥有治疗技能");
    QTreeWidgetItem *z2 = new QTreeWidgetItem(QStringList()<< "巫医" << "后排辅助法师，可以使用奇特的巫术诅咒敌人与治疗队友");
    //用树项目指针作为元素的QList容器 children
    QList<QTreeWidgetItem*> children;
    children.append(l1);
    children.append(l2);
    item1->addChildren(children);
    children.clear();
    children.append(m1);
    children.append(m2);
    item2->addChildren(children);
    children.clear();
    children.append(z1);
    children.append(z2);
    item3->addChildren(children);
}

MainWindow::~MainWindow()
{
    delete ui;
}

