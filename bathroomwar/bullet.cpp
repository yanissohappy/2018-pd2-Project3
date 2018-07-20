#include "bullet.h"
#include "monster.h"
#include "player.h"
//#include "scene.h"

bullet::bullet()
{
    //score=0;
}

void bullet::fly(QObject *B)
{
    Monster* human=qobject_cast<Monster*>(B);
    setPos(x(), y() - 3);
    if(y() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }

    qreal bigrangex= human->x()+90; //to tell whether it collides with the monster
    qreal bigrangey= human->y()+90;
    qreal smallrangex= human->x()-90;
    qreal smallrangey= human->y()-90;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        human->hp=human->hp-100 ;
        human->score=human->score+100;
        //score=score+100;
        this->scene()->removeItem(this);
        delete this;
    }
}


void bullet::fly_left(QObject *B)
{
    Monster* human=qobject_cast<Monster*>(B);
    setPos(x()-1, y() - 3);
    if(y() < 0 || x() < 0) {
        this->scene()->removeItem(this);
        delete this;
    }

    qreal bigrangex= human->x()+90; //to tell whether it collides with the monster
    qreal bigrangey= human->y()+90;
    qreal smallrangex= human->x()-90;
    qreal smallrangey= human->y()-90;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        human->hp=human->hp-100;
        human->score=human->score+100;
        //score=score+100;
        //this->scene()->removeItem(this);
        delete this;
    }
}


void bullet::fly_right(QObject *B)
{
    Monster* human=qobject_cast<Monster*>(B);
    setPos(x()+1, y() - 3);
    if(y() < 0 || x() > 1024 ) {
        //this->scene()->removeItem(this);
        delete this;
    }

    qreal bigrangex= human->x()+90; //to tell whether it collides with the monster
    qreal bigrangey= human->y()+90;
    qreal smallrangex= human->x()-90;
    qreal smallrangey= human->y()-90;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        human->hp=human->hp-100;
        human->score=human->score+100;
        //score=score+100;
        //this->scene()->removeItem(this);
        delete this;
    }
}


/*void bullet::Mfly()
{
    setPos(x()+1, y() + 3);
    if(y() > 0) {
        this->scene()->removeItem(this);
        delete this;
    }
}*/

void bullet::Mfly(QObject *B)
{
    Player* cockroach=qobject_cast<Player*>(B);
    //qreal x=this->x();
    //qreal y=this->y();


    setPos(x()+1, y() + 3);
    qreal bigrangex= cockroach->x()+40; //to tell whether it collides with the monster
    qreal bigrangey= cockroach->y()+40;
    qreal smallrangex= cockroach->x()-40;
    qreal smallrangey= cockroach->y()-40;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        cockroach->hp=cockroach->hp-10;
        //score=score-70;
        cockroach->score=cockroach->score-70;//It dosen't work!!!!!!
        //this->scene()->removeItem(this);
        delete this;
    }
}


void bullet::angryMfly(QObject *B)
{
    Player* cockroach=qobject_cast<Player*>(B);
    //qreal x=this->x();
    //qreal y=this->y();


    setPos(x()+1, y() + 3);
    qreal bigrangex= cockroach->x()+40; //to tell whether it collides with the monster
    qreal bigrangey= cockroach->y()+40;
    qreal smallrangex= cockroach->x()-40;
    qreal smallrangey= cockroach->y()-40;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        cockroach->hp=cockroach->hp-20;
        //score=score-70;
        cockroach->score=cockroach->score-150;//It dosen't work!!!!!!
        //this->scene()->removeItem(this);
        delete this;
    }
}

void bullet::angryMflyleft(QObject *B)
{
    Player* cockroach=qobject_cast<Player*>(B);
    //qreal x=this->x();
    //qreal y=this->y();


    setPos(x()-1, y() + 3);
    qreal bigrangex= cockroach->x()+40; //to tell whether it collides with the monster
    qreal bigrangey= cockroach->y()+40;
    qreal smallrangex= cockroach->x()-40;
    qreal smallrangey= cockroach->y()-40;

    if((x()<=bigrangex) && (x()>=smallrangex) && (y()<=bigrangey) && (y()>=smallrangey)){
        cockroach->hp=cockroach->hp-20;
        //score=score-70;
        cockroach->score=cockroach->score-150;//It dosen't work!!!!!!
        //this->scene()->removeItem(this);
        delete this;
    }
}
