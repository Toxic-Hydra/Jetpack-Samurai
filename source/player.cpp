#include "player.h"

u32 Player::keyHit(u16 keys)
{
    return (this->keyPrev &~ this->key) & keys;
}

Player::Player(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(playerTiles, sizeof(playerTiles))
                    .withSize(SIZE_16_32))
                    .withAnimated(4, 3)
                    .withLocation(x,y)
                    .buildPtr());
}

void Player::dash(u16 keys)
{
    if (this->keyHit(KEY_B))
    {
        int dx = 0;
        int dy = 0;
        if (this->faceDirection == fDirection::LEFT)
        {
            dx = -10;
        }
        else if (this->faceDirection == fDirection::RIGHT)
        {
            dx = 10;
        }
        else if (this->faceDirection == fDirection::UP)
        {
            dy = -10;
        }
        else
        {
            dy = 10;
        }
        this->getSprite()->moveTo(this->getSprite()->getX() + dx, this->getSprite()->getY() + dy);
    }
}

void Player::walk(u16 keys)
{
    if (keys & KEY_LEFT)
    {
        this->getSprite()->animateToFrame(3);
        this->getSprite()->setVelocity(-movementSpeed, this->getSprite()->getDy());
        this->faceDirection = fDirection::LEFT;
    }
    else if (keys & KEY_RIGHT)
    {
        this->getSprite()->animateToFrame(0);
        this->getSprite()->setVelocity(movementSpeed, this->getSprite()->getDy());
        this->faceDirection = fDirection::RIGHT;
    }
    else
    {
        this->getSprite()->setVelocity(0, this->getSprite()->getDy());
    }
    
    if (keys & KEY_UP)
    {
        this->getSprite()->animateToFrame(2);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), -movementSpeed);
        this->faceDirection = fDirection::UP;
    }
    else if (keys & KEY_DOWN)
    {
        this->getSprite()->animateToFrame(1);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), movementSpeed);
        this->faceDirection = fDirection::DOWN;
    }
    else
    {
        this->getSprite()->setVelocity(this->getSprite()->getDx(), 0);
    }
}

// Store the player's input during a single frame
void Player::readInput(u16 keys)
{
    this->keyPrev = this->key;
    this->key = keys;
}

void Player::tick()
{
    // Player can
    // 1) Walk
    // 2) Dash
    this->walk(this->key);
    this->dash(this->key);
}