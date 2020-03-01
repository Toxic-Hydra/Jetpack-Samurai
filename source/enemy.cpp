#include "enemy.h"
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gba/tonc_math.h>

Enemy::Enemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(shieldTiles, 512)
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new ChaseState;

    faceDirection = 0;
    playerVicinity = rc_set2(playerVicinity, this->dest.x, this->dest.y, 16, 32);
    myBoundingBox = rc_set2(myBoundingBox, this->x, this->y, 16, 32);
    innerBox = std::make_unique<CollisionBox>(this->x + 6, this->y + 12, 4, 8); // 4 x 8
    this->setMovementSpeed(1);
}

void Enemy::tick()
{
    // Update Player "bounding box"
    playerVicinity = rc_set_pos(playerVicinity, this->dest.x, this->dest.y);
    myBoundingBox = rc_set_pos(myBoundingBox, this->x, this->y);
    innerBox->setPos(this->getSprite()->getX() + 6, this->getSprite()->getY() + 12);

    EnemyState* currentState = state->update(*this);
    if (currentState != NULL)
    {
        this->state->exit(*this);
        delete this->state;
        this->state = currentState;
        this->state->enter(*this);
    }
}

void Enemy::setPlayerPos(VECTOR destination)
{
    //auto enemyPos = this->getSprite()->getPosAsVector();
    this->dest = destination;
    //this->destCoords = enemyPos.bresenhamLineTo(destination);
}

void IdleStateShield::enter(Enemy& enemy)
{
    //Feature request: have enemy poopoo haha wouldnt it be so cool
}

EnemyState* IdleStateShield::update(Enemy& enemy)
{
    //haha wouldn't that poopoo function be really funny haha
    enemy.getSprite()->setVelocity(0,0);
    VECTOR enemyCenter = enemy.getSprite()->getCenter();
    int distancex = ABS(enemy.getPlayerPos().x+8 - (int)enemyCenter.x);
    int distancey = ABS(enemy.getPlayerPos().y+16 - (int)enemyCenter.y);
    //Account for player direction, if on right you need to offset the distance a little 
    if( distancex >= enemy.getActionDistanceX() && distancey >= enemy.getActionDistanceY())
    {
        return new ChaseState;
    }
    if( distancex < GBA_SCREEN_WIDTH && distancey < GBA_SCREEN_HEIGHT)
    {
        return new ChaseState;
    }
    return NULL;
}

void IdleStateShield::exit(Enemy& enemy)
{

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

    int distancex = ABS(enemy.getPlayerPos().x - (int)enemy.getSprite()->getX());
    int distancey = ABS(enemy.getPlayerPos().y - (int)enemy.getSprite()->getY()); 
    if( distancex < enemy.getActionDistanceX() + 40 || distancey < enemy.getActionDistanceY() + 40)
    {
        return new IdleStateShield;
    }

    //Simple player follow
    if (enemy.getPlayerPos().x < enemy.getSprite()->getPos().x)
    {
        enemy.faceDirection = 0;
        enemy.getSprite()->flipHorizontally(true);
        enemy.getSprite()->setVelocity(-enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(-enemy.getMovementSpeed(), enemy.getSprite()->getDy());
    }
    else if (enemy.getPlayerPos().x > enemy.getSprite()->getPos().x)
    {
        enemy.faceDirection = 1;
        enemy.getSprite()->flipHorizontally(false);
        enemy.getSprite()->setVelocity(enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(enemy.getMovementSpeed(), enemy.getSprite()->getDy());
    }
    else
    {
        enemy.getSprite()->setVelocity(0, enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(0, enemy.getSprite()->getDy());
    }
    
    if (enemy.getPlayerPos().y < enemy.getSprite()->getPos().y)
    {
        
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), -enemy.getMovementSpeed());
        // enemy.innerBox->setVelocity(enemy.getSprite()->getDx(), -enemy.getMovementSpeed());
    }
    else if (enemy.getPlayerPos().y > enemy.getSprite()->getPos().y)
    {
        
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), enemy.getMovementSpeed());
        // enemy.innerBox->setVelocity(enemy.getSprite()->getDx(), enemy.getMovementSpeed());
    }
    else
    {
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), 0);
        // enemy.innerBox->setVelocity(enemy.getSprite()->getDx(), 0);
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
    // enemy.innerBox->setVelocity(0, 0);
    return NULL;
}

void AttackState::exit(Enemy& enemy)
{
    
}