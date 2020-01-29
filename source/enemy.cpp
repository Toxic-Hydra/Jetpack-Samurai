#include "enemy.h"

Enemy::Enemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(tryenemyTiles, sizeof(tryenemyTiles))
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new ChaseState;
}

void Enemy::tick()
{
    state->update(*this);
}

void ChaseState::enter(Enemy& enemy)
{

}

void ChaseState::update(Enemy& enemy)
{
    //ChaseState is supposed to aggresively follow the player. 
    //We can probably do this by periodically grabing the players
    //vector and calling moveTo(Vector) here.
}

void ChaseState::exit(Enemy& enemy)
{

}