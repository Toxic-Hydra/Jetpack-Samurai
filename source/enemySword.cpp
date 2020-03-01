#include "enemySword.h"
#include <libgba-sprite-engine/background/text_stream.h>

EnemySword::EnemySword(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(swordTiles, 512)
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new SwordChaseState;

    playerVicinity = rc_set2(playerVicinity, this->dest.x, this->dest.y, 16, 32);
    myBoundingBox = rc_set2(myBoundingBox, this->x, this->y, 16, 32);
    innerBox = std::make_unique<CollisionBox>(this->x + 6, this->y + 12, 4, 8); // 4 x 8
    // innerBox = std::make_unique<CollisionBox>(this->x, this->y, 16, 32); // 16 x 32
    this->setMovementSpeed(1);
}

void EnemySword::tick()
{
    // Update Player "bounding box"
    playerVicinity = rc_set_pos(playerVicinity, this->dest.x, this->dest.y);
    myBoundingBox = rc_set_pos(myBoundingBox, this->x, this->y);
    innerBox->setPos(this->getSprite()->getX() + 6, this->getSprite()->getY() + 12);

    EnemySwordState* currentState = state->update(*this);
    if (currentState != NULL)
    {
        delete state;
        state = currentState;
    }
}

void EnemySword::setPlayerPos(VECTOR destination)
{
    //auto enemyPos = this->getSprite()->getPosAsVector();
    this->dest = destination;
    //this->destCoords = enemyPos.bresenhamLineTo(destination);
}

void SwordChaseState::enter(EnemySword& enemy)
{

}

EnemySwordState* SwordChaseState::update(EnemySword& enemy)
{
    if(enemy.myBoundingBox->left < enemy.playerVicinity->left + enemy.playerVicinity->right &&
            enemy.myBoundingBox->left + enemy.myBoundingBox->right > enemy.playerVicinity->left &&
            enemy.myBoundingBox->top < enemy.playerVicinity->top + enemy.playerVicinity->bottom &&
            enemy.myBoundingBox->bottom + enemy.myBoundingBox->top > enemy.playerVicinity->top)
    {
        return new SwordAttackState;
    }
    //Simple player follow
    if (enemy.getPlayerPos().x < (enemy.getSprite()->getPos().x - 32))
    {
        enemy.getSprite()->flipHorizontally(true);
        enemy.getSprite()->setVelocity(-enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(-enemy.getMovementSpeed(), enemy.getSprite()->getDy());
    }
    else if (enemy.getPlayerPos().x > (enemy.getSprite()->getPos().x + 32))
    {
        enemy.getSprite()->flipHorizontally(false);
        enemy.getSprite()->setVelocity(enemy.getMovementSpeed(), enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(enemy.getMovementSpeed(), enemy.getSprite()->getDy());
    }
    else
    {
        enemy.getSprite()->setVelocity(0, enemy.getSprite()->getDy());
        // enemy.innerBox->setVelocity(0, enemy.getSprite()->getDy());
    }
    
    if (enemy.getPlayerPos().y < (enemy.getSprite()->getPos().y - 64))
    {
        
        enemy.getSprite()->setVelocity(enemy.getSprite()->getDx(), -enemy.getMovementSpeed());
        // enemy.innerBox->setVelocity(enemy.getSprite()->getDx(), -enemy.getMovementSpeed());
    }
    else if (enemy.getPlayerPos().y > (enemy.getSprite()->getPos().y + 64))
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

void SwordChaseState::exit(EnemySword& enemy)
{

}

void SwordAttackState::enter(EnemySword& enemy)
{

}

EnemySwordState* SwordAttackState::update(EnemySword& enemy)
{
    enemy.getSprite()->setVelocity(0, 0);
    // enemy.innerBox->setVelocity(0, 0);
    return NULL;
}

void SwordAttackState::exit(EnemySword& enemy)
{
    
}