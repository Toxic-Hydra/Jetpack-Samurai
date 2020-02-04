#include "player.h"

u32 Player::keyHit(u16 keys)
{
    return (this->keyPrev &~ this->key) & keys;
}

Player::Player(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(samuraiTiles, 2048)
                    .withSize(SIZE_16_32))
                    .withAnimated(4, 3)
                    .withLocation(x,y)
                    .buildPtr());
    this->setMovementSpeed(2);
}

void Player::useFuel(int x)
{
    if(this->getHealth() - x > 0)
    {
        this->setHealth(this->getHealth() - x);
    }
    else
    {
        this->setHealth(0);
    }
}

void Player::dash()
{
    if (this->keyHit(KEY_B) && this->getHealth() > 10)
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

        // Use fuel at the end of it all
        int fuelAmount = 2;
        this->useFuel(fuelAmount);
    }
}

void Player::walk()
{
    if (this->key & KEY_LEFT)
    {
        this->getSprite()->animateToFrame(3);
        this->getSprite()->setVelocity(-movementSpeed, this->getSprite()->getDy());
        this->faceDirection = fDirection::LEFT;
        this->playerAttackSpriteH->flipHorizontally(true);
    }
    else if (this->key & KEY_RIGHT)
    {
        this->getSprite()->animateToFrame(0);
        this->getSprite()->setVelocity(movementSpeed, this->getSprite()->getDy());
        this->faceDirection = fDirection::RIGHT;
        this->playerAttackSpriteH->flipHorizontally(false);
        
    }
    else
    {
        this->getSprite()->setVelocity(0, this->getSprite()->getDy());
    }
    
    if (this->key & KEY_UP)
    {
        this->getSprite()->animateToFrame(2);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), -movementSpeed);
        this->faceDirection = fDirection::UP;
        this->playerAttackSpriteV->flipVertically(false);
    }
    else if (this->key & KEY_DOWN)
    {
        this->getSprite()->animateToFrame(1);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), movementSpeed);
        this->faceDirection = fDirection::DOWN;
        this->playerAttackSpriteV->flipVertically(true);
    }
    else
    {
        this->getSprite()->setVelocity(this->getSprite()->getDx(), 0);
    }
}

void Player::playerAttack()
{
    if (this->key & KEY_A){
        switch (this->faceDirection)
        {
            case LEFT:
                this->playerAttackSpriteH->moveTo(this->getSprite()->getX()-16,this->getSprite()->getY());
                this->playerAttackSpriteV->moveTo(-100,-100);
                break;
            case RIGHT:
                this->playerAttackSpriteH->moveTo(this->getSprite()->getX()+16,this->getSprite()->getY());
                this->playerAttackSpriteV->moveTo(-100,-100);
                break;
            case UP:
                this->playerAttackSpriteV->moveTo(this->getSprite()->getX(),this->getSprite()->getY()-32);
                this->playerAttackSpriteH->moveTo(-100,-100);
                break;
            case DOWN:
                this->playerAttackSpriteV->moveTo(this->getSprite()->getX(),this->getSprite()->getY()+32);
                this->playerAttackSpriteH->moveTo(-100,-100);
                break;
        }
    } 
    else
    {
        this->playerAttackSpriteH->moveTo(-100,-100);
        this->playerAttackSpriteV->moveTo(-100,-100);
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
    // 3) Attack
    this->walk();
    this->dash();
    this->playerAttack();
}