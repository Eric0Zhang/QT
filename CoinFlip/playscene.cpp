#include "playscene.h"
#include <qaction.h>
#include <QMenuBar>
#include <qdebug.h>
#include <qpainter.h>
#include <iconbutton.h>
#include <qtimer.h>
#include <qlabel.h>
#include <coin.h>
#include <dataconfig.h>
#include <qpropertyanimation.h>
#include <qsound.h>
PlayScene::PlayScene(int level)
{
    qDebug()<<"打开了第"<<level<<"关";
    this->levelNum = level;
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    QString str = QString("糕糕翻金币——第%1关").arg(level);
    setWindowTitle(str);
    setFixedSize(320,588);

    QMenuBar *bar = menuBar();
    setMenuBar(bar);

    QMenu *menu_start= bar->addMenu("开始");
    QAction * exit = menu_start->addAction("退出");
    connect(exit,&QAction::triggered,[=](){
        this->close();
    });

    QSound * backs = new QSound(":/res/BackButtonSound.wav");
    QSound * victory = new QSound(":/res/LevelWinSound.wav");
    QSound * flipvoice = new QSound(":/res/ConFlipSound.wav");
    IconButton * back = new IconButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    back->setParent(this);
    back->move(this->width()-back->width()-5,this->height()-back->height()-5);

    connect(back,&IconButton::clicked,[=](){
        //注意这句话是有问题的，levelScene的父类并不是mainwindow，levelScene只是mainwindow中的一个成员
        //static_cast<QMainWindow*>(this->parent())->show();
        //this->hide();
        backs->play();
        QTimer::singleShot(500,this,[=](){
                emit backPushed();
            });
    });

    QString str2 = QString("Level:%1").arg(level);
    qDebug()<<str2;
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);

    //这种创建，构造函数结束，就释放了，所以必须用指针创建对象
//    QLabel label;//(str2,this);
//    label.setParent(this);
//    label.setText(str2);
//    label.setGeometry(30,height()-50,120,50);
//    label.setFont(font);
    QLabel *label = new QLabel;//(str2,this);
    label->setParent(this);
    label->setText(str2);
    label->setGeometry(110,120,120,50);
    label->setFont(font);

    dataConfig data;

    //创建金币的背景图片
    for(int i = 0 ; i < 4;i++)
    {
      for(int j = 0 ; j < 4; j++)
      {
            //绘制背景图片
            QLabel* label2 = new QLabel;
            label2->setGeometry(0,0,50,50);
            label2->setPixmap(QPixmap(":/res/BoardNode(1).png"));
            label2->setParent(this);
            label2->move(57 + i*50,200+j*50);

            QLabel* labelwin = new QLabel;
            QPixmap pix;
            pix.load(":/res/LevelCompletedDialogBg.png");
            labelwin->setGeometry(0,0,pix.width(),pix.height());
            labelwin->setPixmap(pix);
            labelwin->setParent(this);
            labelwin->move((this->width()-pix.width())*0.5, -pix.height());

            gameArray[i][j] = data.mData[level][i][j];
            Coin *coin;
            if(gameArray[i][j])
             coin = new Coin(":/res/Coin0001.png");
            else
             coin = new Coin(":/res/Coin0008.png");
            coin->setParent(this);
            coin->move(2+label2->x(),4+label2->y());
            coin->pX = i;
            coin->pY = j;
            coin->state = gameArray[i][j];
            pCoinArr[i][j] = coin;
            connect(coin,&Coin::clicked,[=](){
                flipvoice->play();
                for (int i=0;i<4;i++)
                    for (int j=0;j<4;j++)
                    {
                        pCoinArr[i][j]->frozen = 1;
                    }
                //创建动态对象
                coin->flipCoin();
                gameArray[i][j] = !gameArray[i][j];

                QTimer::singleShot(300,this,[=](){
                    //flipvoice->play();
                    if(i>0)
                    {
                    pCoinArr[i-1][j]->flipCoin();
                    gameArray[i-1][j] = !gameArray[i-1][j];
                    }
                    if(i<3)
                    {
                    pCoinArr[i+1][j]->flipCoin();
                    gameArray[i+1][j] = !gameArray[i+1][j];
                    }
                    if(j>0)
                    {
                    pCoinArr[i][j-1]->flipCoin();
                    gameArray[i][j-1] = !gameArray[i][j-1];
                    }
                    if(j<3)
                    {
                    pCoinArr[i][j+1]->flipCoin();
                    gameArray[i][j+1] = !gameArray[i][j+1];
                    }

                    for (int i=0;i<4;i++)
                        for (int j=0;j<4;j++)
                        {
                            pCoinArr[i][j]->frozen = 0;
                        }

                    bool vic_temp = 1;
                    for (int i=0;i<4;i++)
                        for (int j=0;j<4;j++)
                        {
                            if(gameArray[i][j]==0)
                            {
                                vic_temp = 0;
                                break;
                            }
                        }
                    vic = vic_temp;
                    if(vic)
                    {
                        for (int i=0;i<4;i++)
                            for (int j=0;j<4;j++)
                            {
                                pCoinArr[i][j]->frozen = 1;
                            }
                        victory->play();
                        QPropertyAnimation *animation1 = new QPropertyAnimation(labelwin, "geometry");
                        animation1->setDuration(500);
                        animation1->setStartValue(QRect((this->width()-labelwin->width())*0.5, -labelwin->height(),labelwin->width(),labelwin->height()));
                        animation1->setEndValue(QRect((this->width()-labelwin->width())*0.5, labelwin->height(),labelwin->width(),labelwin->height()));
                        animation1->setEasingCurve(QEasingCurve::OutBounce);
                        animation1->start();
                    }
                });

          });
      }
    }

}

void PlayScene::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,width(),height(),pix);

    pix.load(":/res/Title.png");
    painter.drawPixmap(10,30,pix.width()*0.5,pix.height()*0.5,pix);
}
