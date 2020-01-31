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

void Player::dash(u16 keys)
{
    if (keys & KEY_B)
    {
        this->dashTimer->start();
        this->getSprite()->setVelocity(0, 0);
        this->getSprite()->moveTo(this->getSprite()->getX() + 32, this->getSprite()->getY());
    }

    if(this->dashTimer->getSecs() >= 1)
    {
        this->dashTimer->stop();
        this->dashTimer->reset();
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

    //if (keys)
}

// Store the player's input during a single frame
void Player::readInput(u16 keys)
{
    this->key = keys;
}

void Player::tick()
{
    this->canReadInput = this->dashTimer->isActive();

    // If player can read input
    if(this->canReadInput == true)
    {
        // Player can
        // 1) Walk
        // 2) Dash
        this->walk(this->key);
        this->dash(this->key);
    }
}