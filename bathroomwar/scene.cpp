#include "scene.h"

Scene::Scene():
    timer(new QTimer),
    count_timer(new QTimer),
    instant_timer(new QTimer),
    monster_timer(new QTimer),
    signalMapper(new QSignalMapper)
{
    //signalMapper = new QSignalMapper(this);
    connect(timer, SIGNAL(timeout()), signalMapper, SLOT(map()));
    checkgamestart=0; //It's not important here. Instead, initialization of "startwar" in ui is more important than here.
    bigskill=5;
    hppotion=0;
    count=180;
    changeattackmode=0;
    //forscorecount->score=0;
    //score=0;



    QPixmap p,p1;
    p.load(":/img/cockroach.gif");
    /*if(qrand() % 2 == 0) {
        p1.load(":/img/humanbeing1.gif");
       // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
       // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
    } else {
        p1.load(":/img/humanbeing2.gif");
       // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
       // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
    }*/
    p1.load(":/img/humanbeing1.gif");
    cockroach = new Player;
    cockroach->setPixmap((p).scaled(100, 100));
    //cockroach->hp = 100;
    cockroach->setPos(512, 520);

    human = new Monster;
    human->setPixmap((p1).scaled(97, 145));
    //human->hp = 30000;
    human->setPos(512, 40);

    addItem(human);
    addItem(cockroach);

    human->hide();
    cockroach->hide();

    timer->start(10);
    count_timer->start(1000);
    instant_timer->start(0.001);
    monster_timer->start(1000);

}

void Scene::gamestart()
{
    checkgamestart=1;
    changeattackmode=0;
    bigskill=5;
    hppotion=0;
    count=180;
    cockroach->hp = 100;
    human->hp = 30000;
    human->score=0;
    cockroach->score=0;
    cockroach->setPos(512, 520);
    human->setPos(512, 40);
    //forscorecount->score=0;
    //score=0;
    human->show();
    cockroach->show();
}

void Scene::keyPressEvent(QKeyEvent *e) {
    if(checkgamestart!=0) {
        switch(e->key()) {
        if(cockroach->x()>0||cockroach->x()<950||cockroach->y()<550||cockroach->y()>0){
        case Qt::Key_Up:
        case Qt::Key_W:
                if(cockroach->y()<=0){
                    cockroach->setPos(cockroach->x(), 0);
                break;
                }else{
            cockroach->setPos(cockroach->x(), cockroach->y() - 30);
                break;
                }
        case Qt::Key_Down:
        case Qt::Key_S:
                if(cockroach->y()>=550){
                    cockroach->setPos(cockroach->x(), 550);
                break;
                }else{
            cockroach->setPos(cockroach->x(), cockroach->y() + 30);
                break;
                }

        case Qt::Key_Left:
        case Qt::Key_A:
                if(cockroach->x()<=0){
                    cockroach->setPos(0, cockroach->y());
                break;
                }else{
            cockroach->setPos(cockroach->x() - 30, cockroach->y());
                 break;
                }

        case Qt::Key_Right:
        case Qt::Key_D:
                if(cockroach->x()>=950){
                    cockroach->setPos(950, cockroach->y());
                    break;
                }else{
            cockroach->setPos(cockroach->x() + 30, cockroach->y());
            break;
                }
        }


        //normal bullet
        case Qt::Key_Space: {
            //cockroach->hp=cockroach->hp-15;
            bullet *b = new bullet;
           // bullet *c = new bullet;
           // bullet *d = new bullet;
        if(changeattackmode==0){
            if(qrand() % 2 == 0) {
                b->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
               // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
               // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            } else {
                b->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
               // c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
               // d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            }
            b->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - b->pixmap().width() / 2, cockroach->y() - b->pixmap().height());
           // c->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - c->pixmap().width() / 2, cockroach->y() - c->pixmap().height());
           // d->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - d->pixmap().width() / 2, cockroach->y() - d->pixmap().height());

            //connect(timer, SIGNAL(timeout()), signalMapper, SLOT(map()));
            signalMapper->setMapping(timer, human);
            connect(signalMapper, SIGNAL(mapped(QObject *)), b, SLOT(fly(QObject *)));
          //  connect(signalMapper, SIGNAL(mapped(QObject *)), c, SLOT(fly_left(QObject *)));
          //  connect(signalMapper, SIGNAL(mapped(QObject *)), d, SLOT(fly_right(QObject *)));

            /*qreal bigrangex= human->x()+80; //to tell whether it collides with the monster
            qreal bigrangey= human->y()+80;
            qreal smallrangex= human->x()-80;
            qreal smallrangey= human->y()-80;

            if((b->x()<=bigrangex) && (b->x()>=smallrangex) && (b->y()<=bigrangey) && (b->y()>=smallrangey))
                human->hp=human->hp-50;
            if((c->x()<=bigrangex) && (c->x()>=smallrangex) && (c->y()<=bigrangey) && (c->y()>=smallrangey))
                human->hp=human->hp-50;
            if((d->x()<=bigrangex) && (d->x()>=smallrangex) && (d->y()<=bigrangey) && (d->y()>=smallrangey))
                human->hp=human->hp-50;*/
            ///////////////////////////////

            addItem(static_cast<QGraphicsPixmapItem*>(b));
          //  addItem(static_cast<QGraphicsPixmapItem*>(c));
          //  addItem(static_cast<QGraphicsPixmapItem*>(d));
            break;}

        if(changeattackmode==1){
            bullet *b = new bullet;
            bullet *c = new bullet;
            bullet *d = new bullet;
            if(qrand() % 2 == 0) {
                b->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
                c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
                d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            } else {
                b->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
                c->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
                d->setPixmap(QPixmap(":/img/poop.gif").scaled(50, 50));
            }
            b->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - b->pixmap().width() / 2, cockroach->y() - b->pixmap().height());
            c->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - c->pixmap().width() / 2, cockroach->y() - c->pixmap().height());
            d->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - d->pixmap().width() / 2, cockroach->y() - d->pixmap().height());

            //connect(timer, SIGNAL(timeout()), signalMapper, SLOT(map()));
            signalMapper->setMapping(timer, human);
            connect(signalMapper, SIGNAL(mapped(QObject *)), b, SLOT(fly(QObject *)));
            connect(signalMapper, SIGNAL(mapped(QObject *)), c, SLOT(fly_left(QObject *)));
            connect(signalMapper, SIGNAL(mapped(QObject *)), d, SLOT(fly_right(QObject *)));

            addItem(static_cast<QGraphicsPixmapItem*>(b));
            addItem(static_cast<QGraphicsPixmapItem*>(c));
            addItem(static_cast<QGraphicsPixmapItem*>(d));
            break;
        }


        }


        case Qt::Key_B: {
            if(bigskill>0) { //Big skill:directly -10% hp of enemy and recover player 10% hp.
                bigskill--;
                //hppotion--;
                //human->hp=human->hp-25001;
                human->hp=human->hp*0.95;
                cockroach->hp=cockroach->hp*1.05;
                break;
            }
            break;
        }

        case Qt::Key_N: {
            if(changeattackmode==0)
                changeattackmode=1;
            else
                changeattackmode=0;
        break;
    }

        case Qt::Key_C: {
            if(hppotion>0) { //Big skill:directly -10% hp of enemy and recover player 10% hp.
                hppotion--;
                if(cockroach->hp >= 100)
                    break;
                else if(cockroach->hp >=0 || cockroach->hp <=95)
                    cockroach->hp = cockroach->hp+5;
                else if(cockroach->hp >95 && cockroach->hp <100)
                    cockroach->hp = 100;
            }
            break;
        }
        }
    }

}
/*
void Scene::mousePressEvent(QMouseEvent *e) {
    if(checkgamestart!=0) {
        human->hp = human->hp-500;
        cockroach->hp = cockroach->hp-50;
        bullet *b = new bullet;
        bullet *c = new bullet;
        bullet *d = new bullet;

        if(qrand() % 2 == 0) {
            b->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
            c->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
            d->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
        } else {
            b->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
            c->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
            d->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
        }
        b->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - b->pixmap().width() / 2, cockroach->y() - b->pixmap().height());
        c->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - c->pixmap().width() / 2, cockroach->y() - c->pixmap().height());
        d->setPos(cockroach->x() + cockroach->pixmap().width() / 2 - d->pixmap().width() / 2, cockroach->y() - d->pixmap().height());

        b->connect(timer, SIGNAL(timeout()), b, SLOT(fly()));
        c->connect(timer, SIGNAL(timeout()), c, SLOT(fly_left()));
        d->connect(timer, SIGNAL(timeout()), d, SLOT(fly_right()));

        addItem(static_cast<QGraphicsPixmapItem*>(b));
        addItem(static_cast<QGraphicsPixmapItem*>(c));
        addItem(static_cast<QGraphicsPixmapItem*>(d));
    }
}
*/

int Scene::totalscore()
{
    return human->score + cockroach->score;
}


