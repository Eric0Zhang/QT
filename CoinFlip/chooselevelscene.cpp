#include "chooselevelscene.h"
#include <QMenuBar>
#include <qmenu.h>
#include <qaction.h>
#include <qpainter.h>
#include <iconbutton.h>
#include <qtimer.h>
#include <qlabel.h>
#include <qdebug.h>
#include <playscene.h>
#include <qsound.h>
ChooseLevelScene::ChooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    setWindowTitle("选择关卡");
    setFixedSize(320,588);

    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    QMenu *menu_start= bar->addMenu("开始");
    QAction * exit = menu_start->addAction("退出");
    connect(exit,&QAction::triggered,[=](){
        this->close();
    });

    QSound * back = new QSound(":/res/BackButtonSound.wav");

    IconButton *ibtn = new IconButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    ibtn->setParent(this);
    ibtn->move(this->width()-ibtn->width()-5,this->height()-ibtn->height()-5);

    connect(ibtn,&IconButton::clicked,[=](){
        //注意这句话是有问题的，levelScene的父类并不是mainwindow，levelScene只是mainwindow中的一个成员
        //static_cast<QMainWindow*>(this->parent())->show();
        //this->hide();
        back->play();
        QTimer::singleShot(500,this,[=](){
                emit backPushed();
            });
    });

    for(int i=0;i<20;i++)
    {
        IconButton * level = new IconButton(":/res/LevelIcon.png");
        level->setParent(this);
        level->move(i%4*70 + 25,i/4*70+130);

        connect(level,&IconButton::clicked,[=](){
           //QString str = QString("您选择的是第%1关").arg(i+1);
           //qDebug() << str;
            this->hide();
            PlayScene * playscene = new PlayScene(i+1);
            playscene->vic = 0;
            playscene->setGeometry(this->geometry());
            playscene->show();
            //监听levelScene必须放在创建对象以后,编译器不允许监听为创建的对象
            connect(playscene,&PlayScene::backPushed,[=](){
                this->setGeometry(playscene->geometry());
                this->show();
                delete playscene;
            });
        });

        //注意LABEL在按钮上面，鼠标点击事件被挡住了。
        QLabel * label = new QLabel;
        label->setParent(this);
        label->setFixedSize(level->width(),level->height());
        label->setText(QString::number(i+1));
        label->move(i%4*70 + 25,i/4*70+130);
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        //设置鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

void ChooseLevelScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,width(),height(),pix);
    pix.load(":/res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5,30,pix.width(),pix.height(),pix);
}
