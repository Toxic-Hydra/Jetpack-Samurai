#include "enemy.h"
#include <libgba-sprite-engine/background/text_stream.h>

Enemy::Enemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(shieldTiles, 512)
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new ChaseState;

    playerVicinity = rc_set2(playerVicinity, this->dest.x, this->dest.y, 16, 32);
    myBoundingBox = rc_set2(myBoundingBox, this->x, this->y, 16, 32);
    this->setMovementSpeed(1);
}

void Enemy::tick()
{
    // Update Player "bounding box"
    playerVicinity = rc_set_pos(playerVicinity, this->dest.x, this->dest.y);
    myBoundingBox = rc_set_pos(myBoundingBox, this->x, this->y);

    EnemyState* currentState = state->update(*this);
    if (currentState != NULL)
    {
        delete state;
        state = currentState;
    }
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

EnemyState* ChaseState::update(Enemy& enemy)
{
    if(enemy.myBoundingBox->left < enemy.playerVicinity->left + enemy.playerVicinity->right &&
            enemy.myBoundingBox->left + enemy.myBoundingBox->right > enemy.playerVicinity->left &&
            enemy.myBoundingBox->top < enemy.playerVicinity->top + enemy.playerVicinity->bottom &&
            enemy.myBoundingBox->bottom + enemy.myBoundingBox->top > enemy.playerVicinity->top)
    {
        return new AttackState;
    }
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
    return NULL;
}

void ChaseState::exit(Enemy& enemy)
{

}

void AttackState::enter(Enemy& enemy)
{

}

EnemyState* AttackState::update(Enemy& enemy)
{
    enemy.getSprite()->setVelocity(0, 0);

    return NULL;
}

void AttackState::exit(Enemy& enemy)
{
    
}