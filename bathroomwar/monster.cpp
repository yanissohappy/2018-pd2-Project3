#include "monster.h"
#include <QDebug>
Monster::Monster()
{

}

void Monster::move()
{
    qreal x,y;
    x=this->x();
    y=this->y();

    x=qrand()%800+40;
    y=qrand()%180+30;

    /*if((x >= 500) || (y >= 100)){
        x=x+50;
        y=y+130;
    }
    if((x >= 1000) || (y >= 200)){
        x=x-170;
        y=y-70;
    }
    if((x <= 0) || (y <= 0)){
        x=512;
        y=60;
    }*/

    setPos(x, y);

    /*if(x( ) >= 1000 || y() >= 250)
        {
            setPos(x()-1000, y()-220);
            //qDebug()<<"it really works."<<endl;
        }

        else if(x() <= 0 || y() <= 0)
        {
            setPos(x()+10, y()+10);
            //qDebug()<<"it really works."<<endl;
        }*/
}



void Monster::shoot()
{
    /*bullet *A = new bullet;

    A->setPixmap(QPixmap(":/img/medjed.gif").scaled(50, 50));
    A->setPos(this->x() + this->pixmap().width() / 2 - A->pixmap().width() / 2, this->y() - A->pixmap().height());
    signalMapper->setMapping(timer, cockroach);
    connect(signalMapper, SIGNAL(mapped(QObject *)), A, SLOT(Mfly(QObject *)));
    scene->addItem(static_cast<QGraphicsPixmapItem*>(A));*/
}
