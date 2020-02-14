#include "player.h"
#include <iostream>
#include <libgba-sprite-engine/background/text_stream.h>

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

    if(this->state == NULL)
        state = new player_ns::UnrestrictedState;
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
    // if (this->keyHit(KEY_B) && this->getHealth() > 10)
    if (this->getHealth() > 10)
    {
        int dx = 0;
        int dy = 0;
        if (this->faceDirection == fDirection::LEFT)
        {
            dx = -20;
        }
        else if (this->faceDirection == fDirection::RIGHT)
        {
            dx = 20;
        }
        else if (this->faceDirection == fDirection::UP)
        {
            dy = -20;
        }
        else
        {
            dy = 20;
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
    }
    else if (this->key & KEY_RIGHT)
    {
        this->getSprite()->animateToFrame(0);
        this->getSprite()->setVelocity(movementSpeed, this->getSprite()->getDy());
        this->faceDirection = fDirection::RIGHT;
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
    }
    else if (this->key & KEY_DOWN)
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

void Player::playerAttack()
{
    // if (this->key & KEY_A){
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
    // } 
    // else
    // {
        // this->playerAttackSprite->moveTo(-100,-100);
    // }
}

void Player::lockMovement()
{
    this->getSprite()->setVelocity(0, 0);
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
    // this->walk();
    // this->dash();
    // this->playerAttack();

    player_ns::PlayerState* currentState = this->state->update(*this);
    if (currentState != NULL)
    {
        this->state->exit(*this);
        delete this->state;
        this->state = currentState;
        this->state->enter(*this);
    }
}

//////////////////////////////////////////////////////////////////
//
//
// Player States Stuff
//
//
//////////////////////////////////////////////////////////////////

void player_ns::UnrestrictedState::enter(Player& player)
{
    // TextStream::instance().setText("Inside Unrestricted State: enter\n", 4, 0);
}

player_ns::PlayerState* player_ns::UnrestrictedState::update(Player& player)
{
    // TextStream::instance().setText("Inside Unrestricted State: up, 4, 0)date()\n";
    player.walk();
    if (player.keyHit(KEY_B))
        return new player_ns::DashState;
    else if (player.keyHit(KEY_A))
        return new player_ns::AttackState;
    // player.playerAttack();
    else if (player.getKey() & KEY_R)
        return new player_ns::BlockState;
    return NULL;
}

void player_ns::UnrestrictedState::exit(Player& player)
{
    // TextStream::instance().setText("Inside Unrestricted State: exit()\n", 4, 0);
}

player_ns::DamagedState::DamagedState(int dmg, int dx, int dy)
{
    damage = dmg;
    dx_ = dx;
    dy_ = dy;
}

void player_ns::DamagedState::enter(Player& player)
{
    TextStream::instance().setText("Inside Damaged State: enter()\n", 4, 0);
}

player_ns::PlayerState* player_ns::DamagedState::update(Player& player)
{
    // TextStream::instance().setText("Inside Damaged State: update(, 4, 0))\n";
    player.useFuel(damage);
    player.getSprite()->moveTo(player.getSprite()->getX() + dx_, player.getSprite()->getY() + dy_);
    return new player_ns::UnrestrictedState;
}

void player_ns::DamagedState::exit(Player& player)
{
    TextStream::instance().setText("Inside Damaged State: exit()\n", 4, 0);
}

void player_ns::AttackState::enter(Player& player)
{
    TextStream::instance().setText("Inside Attack State: enter()\n", 4, 0);
}

player_ns::PlayerState* player_ns::AttackState::update(Player& player)
{
    // TextStream::instance().setText("Inside Attack State: update(), 4, 0)\n";
    if (player.getKey() & KEY_A)
    {
        player.playerAttack();
        player.lockMovement();
        return NULL;
    }
    return new player_ns::UnrestrictedState;
}

void player_ns::AttackState::exit(Player& player)
{
    TextStream::instance().setText("Inside Attack State: exit()\n", 4, 0);
    player.playerAttackSprite->moveTo(-100, -100);
}

void player_ns::DashState::enter(Player& player)
{
    TextStream::instance().setText("Inside Dash State: enter()\n", 4, 0);
}

player_ns::PlayerState* player_ns::DashState::update(Player& player)
{
    // TextStream::instance().setText("Inside Dash State: update()\n, 4, 0)";
    player.dash();
    return new player_ns::UnrestrictedState;
}

void player_ns::DashState::exit(Player& player)
{
    TextStream::instance().setText("Inside Dash State: exit()\n", 4, 0);
}

void player_ns::BlockState::enter(Player& player)
{
    TextStream::instance().setText("Inside Block State: enter()\n", 4, 0);
}

player_ns::PlayerState* player_ns::BlockState::update(Player& player)
{
    // TextStream::instance().setText("Inside Block State: update()\, 4, 0)n";
    if (!(player.getKey() & KEY_R))
    {
        return new player_ns::UnrestrictedState;
    }
    player.lockMovement();
    return NULL;
}

void player_ns::BlockState::exit(Player& player)
{
    TextStream::instance().setText(std::to_string(player.state->stateID), 4, 0);
}