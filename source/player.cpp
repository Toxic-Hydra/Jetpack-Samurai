#include "player.h"

Player::Player(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(avatarTiles, sizeof(avatarTiles))
                    .withSize(SIZE_64_64))
                    .withLocation(x,y)
                    .buildPtr());
}

void Player::moveWithDPad(u16 keys)
{
    if (keys & KEY_LEFT)
    {
        this->getSprite()->setVelocity(-movementSpeed, 0);
    }
    else if (keys & KEY_RIGHT)
    {
        this->getSprite()->setVelocity(movementSpeed, 0);
    }
    else if (keys & KEY_UP)
    {
        this->getSprite()->setVelocity(0, -movementSpeed);
    }
    else if (keys & KEY_DOWN)
    {
        this->getSprite()->setVelocity(0, movementSpeed);
    }
    else
    {
        this->getSprite()->setVelocity(0, 0);
    }
}