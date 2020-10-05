#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <coin.h>
class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    PlayScene(int level);
    void paintEvent(QPaintEvent*);
    int levelNum;
    int gameArray[4][4];
    Coin *pCoinArr[4][4];
    bool vic=0;
signals:
    void backPushed();

};

#endif // PLAYSCENE_H
