#include "character.h"

#include <QDebug>
Character::Character(QObject *parent) : QObject(parent)
{
    score=0;
}

void Character::move()
{
    /*setPos(x()+ 10, y());

    if(x( ) >= 1000)
    {
        setPos(x()-1000, y());
        qDebug()<<"it really works."<<endl;
    }

    else if(x() <= 0)
    {
        setPos(x()+10, y());
        qDebug()<<"it really works."<<endl;
    }
*/

}

void Character::shoot()
{


}
