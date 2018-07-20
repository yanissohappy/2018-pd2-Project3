#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
#include <QSignalMapper>

#include "bullet.h"
#include "character.h"
#include "player.h"
#include "monster.h"
#include "scene.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //void gametitle();
    Scene *scene;
    //QGraphicsScene *scene;
    //QGraphicsPixmapItem *player;

    /*QTimer *timer;
    QTimer *count_timer;
    QTimer *instant_timer;
    QTimer *monster_timer;*/
    //Player *cockroach;
    //Monster *human;
    //QMediaPlayer *bgm;
    //int checkgamestart;
    //int bigskill;
    //int count;
    //int hppotion;


public slots:
    //virtual void keyPressEvent(QKeyEvent *e);
    //virtual void mousePressEvent(QMouseEvent *e);
    void timedisplay();
    void timedisplay_instantly();
    void gametitle();
private slots:
    void startwar();
    void exitwar();
    void gameinstruction();
    void backgametitle();
    void PcollideM();
    void restartwar();
private:
    Ui::MainWindow *ui;
    QSignalMapper *signalMapper1;


};

#endif // MAINWINDOW_H
