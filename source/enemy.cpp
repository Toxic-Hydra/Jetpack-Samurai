#include "enemy.h"
#include <libgba-sprite-engine/background/text_stream.h>

Enemy::Enemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(tryenemyTiles, sizeof(tryenemyTiles))
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new ChaseState;
    this->setMovementSpeed(1);
}

void Enemy::tick()
{
    state->update(*this);
}

void Enemy::setPlayerPos(VECTOR destination)
{
    //auto enemyPos = this->getSprite()->getPosAsVector();
    this->dest = destination;
    //this->destCoords = enemyPos.bresenhamLineTo(destination);
}


void ChaseState::enter(Enemy& enemy)
{

}

void ChaseState::update(Enemy& enemy)
{
    //Simple player follow
    if (enemy.getPlayerPos().x < enemy.getSprite()->getPos().x)
    {
        
        enemy.getSprite()->setVelocity(-enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        
    }
    else if (enemy.getPlayerPos().x > enemy.getSprite()->getPos().x)
    {
        
        enemy.getSprite()->setVelocity(enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        
    }
    else
    {
        enemy.getSprite()->setVelocity(0, enemy.getSprite()->getDy());
    }
    
    if (enemy.getPlayerPos().y < enemy.getSprite()->getPos().y)
    {
        
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), -enemy.getMovementSpeed());
        
    }
    else if (enemy.getPlayerPos().y > enemy.getSprite()->getPos().y)
    {
        
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), enemy.getMovementSpeed());
        
    }
    else
    {
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), 0);
    }
}

void ChaseState::exit(Enemy& enemy)
{

}