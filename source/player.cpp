#include "player.h"
// #include "playerTiles.h"

Player::Player(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(playerTiles, sizeof(playerTiles))
                    .withSize(SIZE_16_32))
                    .withAnimated(4, 3)
                    .withLocation(x,y)
                    .buildPtr());
}

void Player::moveWithDPad(u16 keys)
{
    if (keys & KEY_LEFT)
    {
        this->getSprite()->animateToFrame(3);
        this->getSprite()->setVelocity(-movementSpeed, 0);
    }
    else if (keys & KEY_RIGHT)
    {
        this->getSprite()->animateToFrame(0);
        this->getSprite()->setVelocity(movementSpeed, 0);
    }
    else if (keys & KEY_UP)
    {
        this->getSprite()->animateToFrame(2);
        this->getSprite()->setVelocity(0, -movementSpeed);
    }
    else if (keys & KEY_DOWN)
    {
        this->getSprite()->animateToFrame(1);
        this->getSprite()->setVelocity(0, movementSpeed);
    }
    else
    {
        this->getSprite()->setVelocity(0, 0);
    }
}