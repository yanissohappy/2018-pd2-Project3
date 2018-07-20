#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QCoreApplication>
#include <QPushButton>
#include <QTimer>
#include <QLCDNumber>
#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QSound>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QGraphicsProxyWidget>
#include <QHoverEvent>
#include <QDebug>
#include <QMouseEvent>
#include <QSignalMapper>

#include "bullet.h"
#include "character.h"
#include "player.h"
#include "monster.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    Scene();
    void gamestart();
    Player *cockroach;
    Character *human; //I will use polymorphism here.


    QTimer *timer;
    QTimer *count_timer;
    QTimer *instant_timer;
    QTimer *monster_timer;
    //bullet *forscorecount;

    int checkgamestart;
    int bigskill;
    int hppotion;
    int count;
    int totalscore();
    int changeattackmode;
    //int score;


public slots:
    void keyPressEvent(QKeyEvent *);
    //void mousePressEvent(QMouseEvent *);
    //void PcollideM();
private:
    QSignalMapper *signalMapper;
};

#endif // SCENE_H
