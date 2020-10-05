#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qicon.h>
#include <qpainter.h>
#include <iconbutton.h>
#include <qpropertyanimation.h>
#include <qsequentialanimationgroup.h>
#include <qdebug.h>
#include <qtimer.h>
#include <qsound.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("糕糕翻金币");
    setFixedSize(320,588);

    QSound *start = new QSound(":/res/TapButtonSound.wav");


    connect(ui->actionquit, &QAction::triggered,[=](){
        close();
    });
    IconButton *btn = new IconButton(":/res/MenuSceneStartButton.png");
    btn->setParent(this);
    btn->move((this->width()-btn->width())*0.5, this->height()*0.7);
    QSize sz = ui->testbtn->size();
    qDebug()<<sz;
    levelScene = new ChooseLevelScene;
    //监听levelScene必须放在创建对象以后,编译器不允许监听为创建的对象
    connect(levelScene,&ChooseLevelScene::backPushed,[=](){
        this->setGeometry(levelScene->geometry());
        levelScene->hide();
        this->show();
    });
    connect(btn,&IconButton::clicked,[=](){
        start->play();
        btn->zoom1();
        btn->zoom2();

        QPropertyAnimation *animation1 = new QPropertyAnimation(ui->testbtn, "size");
        animation1->setDuration(500);
        animation1->setStartValue(sz);
        animation1->setEndValue(QSize(100, 100));

        QPropertyAnimation *animation2 = new QPropertyAnimation(ui->testbtn, "size");
        animation2->setDuration(500);
        animation2->setStartValue(QSize(100, 100));
        animation2->setEndValue(sz);

        QSequentialAnimationGroup *sequGroup = new QSequentialAnimationGroup(this);
        sequGroup->addAnimation(animation1);
        sequGroup->addPause(300);
        sequGroup->addAnimation(animation2);
        sequGroup->start();


        QTimer::singleShot(1500,this,[=](){
            levelScene->setGeometry(this->geometry());
            this->hide();
            levelScene->show();
        });
    });


}

void MainWindow::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/MenuSceneBg.png");
    painter.drawPixmap(0,0,width(),height(),pix);
//    pix.load(":/res/Title.png");
//    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
//    painter.drawPixmap(10,30,pix);
}

MainWindow::~MainWindow()
{
    delete ui;
}

