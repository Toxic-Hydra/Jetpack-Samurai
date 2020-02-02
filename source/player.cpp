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
    this->setMovementSpeed(2);
}

void Player::moveWithDPad(u16 keys)
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

void Player::playerAttack(u16 keys)
{
    if (keys & KEY_A){
        switch (this->faceDirection)
        {
            case LEFT:
                this->playerAttackSprite->moveTo(this->getSprite()->getX()-16,this->getSprite()->getY());
                break;
            case RIGHT:
                this->playerAttackSprite->moveTo(this->getSprite()->getX()+16,this->getSprite()->getY());
                break;
            case UP:
                this->playerAttackSprite->moveTo(this->getSprite()->getX(),this->getSprite()->getY()-32);
                break;
            case DOWN:
                this->playerAttackSprite->moveTo(this->getSprite()->getX(),this->getSprite()->getY()+32);
                break;
        }
    } 
    else
    {
        this->playerAttackSprite->moveTo(-100,-100);
    } 
}