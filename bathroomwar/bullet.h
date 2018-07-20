#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>



class Monster;
class Player;


class bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    bullet();
    int score;

public slots:
    void fly(QObject *);
    void fly_left(QObject *);
    void fly_right(QObject *);
    //void Mfly();
    void Mfly(QObject *);
    void angryMfly(QObject *);
    void angryMflyleft(QObject *);


    //int score;
};

#endif // BULLET_H
