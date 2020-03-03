#include "player.h"
#include <iostream>
#include <libgba-sprite-engine/background/text_stream.h>

std::unique_ptr<Timer> Player::dashTimer;

u32 Player::keyHit(u16 keys)
{
    return (this->keyPrev &~ this->key) & keys;
}

Player::Player(int x, int y) : Entity(x, y)
{
    this->setSprite(spriteBuilder
                    .withData(playerSheetTiles, sizeof(playerSheetTiles))
                    .withSize(SIZE_16_32)
                    .withAnimated(30, 3)
                    .withLocation(x,y)
                    .withinBounds()
                    .buildPtr());
    this->setMovementSpeed(2);
    Player::dashTimer = std::make_unique<Timer>();
    this->faceDirection = 1;

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
    int dx = 0;
    int dy = 0;
    if (this->faceDirection == 0)
    {
        dx = -dashSpeed;
    }
    else if (this->faceDirection == 1)
    {
        dx = dashSpeed;
    }
    else if (this->faceDirection == 2)
    {
        dy = -dashSpeed;
    }
    else
    {
        dy = dashSpeed;
    }
    // this->getSprite()->moveTo(this->getSprite()->getX() + dx, this->getSprite()->getY() + dy);
    this->getSprite()->setVelocity(dx, dy);
}

void Player::walk()
{
    // If holding a horizontal direction, use the right-facing running animaiton
    if ((this->key & KEY_LEFT) || (this->key & KEY_RIGHT))
    {
        if (!this->getSprite()->isAnimating() || (this->getSprite()->getCurrentFrame() < 3 || this->getSprite()->getCurrentFrame() > 14))
        {
            this->getSprite()->makeAnimated(4, 10, 3);
        }
    }
    
    if (this->key & KEY_LEFT)
    {
        this->getSprite()->flipHorizontally(true);
        this->getSprite()->setVelocity(-movementSpeed, this->getSprite()->getDy());
        this->faceDirection = 0;
    }
    else if (this->key & KEY_RIGHT)
    {
        this->getSprite()->flipHorizontally(false);
        this->getSprite()->setVelocity(movementSpeed, this->getSprite()->getDy());
        this->faceDirection = 1;
    }
    else
    {
        this->getSprite()->setVelocity(0, this->getSprite()->getDy());
    }
    
    if (this->key & KEY_UP)
    {
        this->getSprite()->animateToFrame(2);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), -movementSpeed);
        this->faceDirection = 2;
    }
    else if (this->key & KEY_DOWN)
    {
        this->getSprite()->animateToFrame(1);
        this->getSprite()->setVelocity(this->getSprite()->getDx(), movementSpeed);
        this->faceDirection = 3;
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
            case 0:
                this->getSprite()->flipHorizontally(true);
                this->playerAttackSprite->moveTo(this->getSprite()->getX()-16,this->getSprite()->getY());
                this->playerAttackSprite->flipHorizontally(true);
                break;
            case 1:
                this->getSprite()->flipHorizontally(false);
                this->playerAttackSprite->moveTo(this->getSprite()->getX()+16,this->getSprite()->getY());
                this->playerAttackSprite->flipHorizontally(false);
                break;
            case 2:
                this->attackBottom->moveTo(this->getSprite()->getX()-8,this->getSprite()->getY()-16);
                this->attackBottom->flipVertically(true);
                break;
            case 3:
                this->attackBottom->moveTo(this->getSprite()->getX()-8,this->getSprite()->getY()+32);
                this->attackBottom->flipVertically(false);
                break;
        }
        // this->getSprite()->makeAnimated(25, 8, 3);
        // this->playerAttackSprite->makeAnimated(33, 8, 3);
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
    TextStream::instance().setText("Inside Unrestricted State: enter\n", 4, 0);
    // spriteBuilder = std::unique_ptr<SpriteBuilder<Sprite>>(new SpriteBuilder<Sprite>);
    // player.setSprite(spriteBuilder->withData(samuraiTiles, 512)
    //                 .withSize(SIZE_16_32)
    //                 .withAnimated(4, 3)
    //                 .withLocation(player.getSprite()->getX(), player.getSprite()->getY())
    //                 .buildPtr());
}

player_ns::PlayerState* player_ns::UnrestrictedState::update(Player& player)
{
    // TextStream::instance().setText("Inside Unrestricted State: up, 4, 0)date()\n";
    if ((player.getKey() & KEY_LEFT) ||
        (player.getKey() & KEY_RIGHT) ||
        (player.getKey() & KEY_UP) ||
        (player.getKey() & KEY_DOWN))
    {
        player.walk();
    }
    else
    {
        player.getSprite()->stopAnimating();
        switch (player.faceDirection)
        {
            case 0:
            case 1: // If faceDirection == LEFT || RIGHT
                player.getSprite()->animateToFrame(0);
                break;
            case 2:
                player.getSprite()->animateToFrame(2);
                break;
            case 3:
                player.getSprite()->animateToFrame(1);
                break;
        }
        player.getSprite()->setVelocity(0, 0);
    }
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
    TextStream::instance().setText("Inside Unrestricted State: exit()\n", 4, 0);
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
    TextStream::instance().setText("Inside Damaged State: update()\n", 4, 0);
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
    player.getSprite()->makeAnimated(13, 8, 3);
    player.playerAttackSprite->makeAnimated(0, 8, 3);
}

player_ns::PlayerState* player_ns::AttackState::update(Player& player)
{
    TextStream::instance().setText("Inside Attack State: update()\n", 4, 0);
    if (player.getSprite()->getCurrentFrame() != 13 + 7)// (player.getKey() & KEY_A)
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
    // player.getSprite()->animateToFrame(0);
    player.playerAttackSprite->animateToFrame(0);
    player.playerAttackSprite->moveTo(-100, -100);
    player.attackBottom->moveTo(-100,-100);
}

void player_ns::DashState::enter(Player& player)
{
    TextStream::instance().setText("Inside Dash State: enter()\n", 4, 0);
    player.getDashTimer()->reset();
    player.getDashTimer()->start();
}

player_ns::PlayerState* player_ns::DashState::update(Player& player)
{
    // TextStream::instance().setText("Inside Dash State: update()\n, 4, 0)";
    player.getDashTimer()->onvblank();
    if (player.getDashTimer()->getMsecs() < 150)
    {
        if (player.getHealth() > 10)
        {
            player.dash();
        }
        else
        {
            player.lockMovement(); // Jetpack failure without enough fuel maybe?
        }
        return NULL;
    }
    return new player_ns::UnrestrictedState;
}

void player_ns::DashState::exit(Player& player)
{
    TextStream::instance().setText("Inside Dash State: exit()\n", 4, 0);
    player.getDashTimer()->stop();

    // Use fuel at the end of it all
    if (player.getHealth() > 10)
    {
        player.useFuel(10);
    }
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
    TextStream::instance().setText("Inside Block State: exit()\n", 4, 0);
}
