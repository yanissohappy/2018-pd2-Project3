#ifndef MONSTER_H
#define MONSTER_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include "character.h"


class Monster : public Character
{
    Q_OBJECT
public:
    Monster();
    //QTimer *Mtimer;
    //bullet *A;

public slots:
    virtual void move();
    virtual void shoot();
};

#endif // MONSTER_H
