#ifndef PLAYER_H
#define PLAYER_H

#include "character.h"

#include <QObject>

class Player : public Character
{
    Q_OBJECT
public:
    Player();
};

#endif // PLAYER_H
