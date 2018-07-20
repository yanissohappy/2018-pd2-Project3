#ifndef CHARACTER_H
#define CHARACTER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "bullet.h"


class Character : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Character(QObject *parent = 0);

    int hp;
    int score;

public slots:
    virtual void move();
    virtual void shoot();

};

#endif // CHARACTER_H
