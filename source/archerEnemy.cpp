#include "archerEnemy.h"
#include <libgba-sprite-engine/background/text_stream.h>

ArcherEnemy::ArcherEnemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(shieldTiles, sizeof(shieldTiles))
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());

    if(this->state == NULL)
        state = new archer_nme_ns::ChaseState;

    faceDirection = 0;
    playerVicinity = rc_set2(playerVicinity, this->dest.x, this->dest.y, 16, 32);
    myBoundingBox = rc_set2(myBoundingBox, this->x, this->y, 16, 32);
    innerBox = std::make_unique<CollisionBox>(this->x + 6, this->y + 12, 4, 8); // 4 x 8
    this->setMovementSpeed(1);
}

void ArcherEnemy::tick()
{
    // Update Player "bounding box"
    playerVicinity = rc_set_pos(playerVicinity, this->dest.x, this->dest.y);
    myBoundingBox = rc_set_pos(myBoundingBox, this->x, this->y);
    innerBox->setPos(this->getSprite()->getX() + 6, this->getSprite()->getY() + 12);

    archer_nme_ns::ArcherEnemyState* currentState = state->update(*this);
    if (currentState != NULL)
    {
        this->state->exit(*this);
        delete this->state;
        this->state = currentState;
        this->state->enter(*this);
    }
}

void ArcherEnemy::setPlayerPos(VECTOR destination)
{
    //auto enemyPos = this->getSprite()->getPosAsVector();
    this->dest = destination;
    //this->destCoords = enemyPos.bresenhamLineTo(destination);
}

void archer_nme_ns::ChaseState::enter(ArcherEnemy& archerEnemy)
{

}

archer_nme_ns::ArcherEnemyState* archer_nme_ns::ChaseState::update(ArcherEnemy& archerEnemy)
{
    if(archerEnemy.myBoundingBox->left < archerEnemy.playerVicinity->left + archerEnemy.playerVicinity->right &&
            archerEnemy.myBoundingBox->left + archerEnemy.myBoundingBox->right > archerEnemy.playerVicinity->left &&
            archerEnemy.myBoundingBox->top < archerEnemy.playerVicinity->top + archerEnemy.playerVicinity->bottom &&
            archerEnemy.myBoundingBox->bottom + archerEnemy.myBoundingBox->top > archerEnemy.playerVicinity->top)
    {
        return new archer_nme_ns::AttackState;
    }
    //Simple player follow
    if (archerEnemy.getPlayerPos().x < archerEnemy.getSprite()->getPos().x)
    {
        archerEnemy.faceDirection = 0;
        archerEnemy.getSprite()->flipHorizontally(true);
        archerEnemy.getSprite()->setVelocity(-archerEnemy.getMovementSpeed(), archerEnemy.getSprite()->getDy());
        // archerEnemy.innerBox->setVelocity(-archerEnemy.getMovementSpeed(), archerEnemy.getSprite()->getDy());
    }
    else if (archerEnemy.getPlayerPos().x > archerEnemy.getSprite()->getPos().x)
    {
        archerEnemy.faceDirection = 1;
        archerEnemy.getSprite()->flipHorizontally(false);
        archerEnemy.getSprite()->setVelocity(archerEnemy.getMovementSpeed(), archerEnemy.getSprite()->getDy());
        // archerEnemy.innerBox->setVelocity(archerEnemy.getMovementSpeed(), archerEnemy.getSprite()->getDy());
    }
    else
    {
        archerEnemy.getSprite()->setVelocity(0, archerEnemy.getSprite()->getDy());
        // archerEnemy.innerBox->setVelocity(0, archerEnemy.getSprite()->getDy());
    }
    
    if (archerEnemy.getPlayerPos().y < archerEnemy.getSprite()->getPos().y)
    {
        
        archerEnemy.getSprite()->setVelocity(archerEnemy.getSprite()->getDx(), -archerEnemy.getMovementSpeed());
        // archerEnemy.innerBox->setVelocity(archerEnemy.getSprite()->getDx(), -archerEnemy.getMovementSpeed());
    }
    else if (archerEnemy.getPlayerPos().y > archerEnemy.getSprite()->getPos().y)
    {
        
        archerEnemy.getSprite()->setVelocity(archerEnemy.getSprite()->getDx(), archerEnemy.getMovementSpeed());
        // archerEnemy.innerBox->setVelocity(archerEnemy.getSprite()->getDx(), archerEnemy.getMovementSpeed());
    }
    else
    {
        archerEnemy.getSprite()->setVelocity(archerEnemy.getSprite()->getDx(), 0);
        // archerEnemy.innerBox->setVelocity(archerEnemy.getSprite()->getDx(), 0);
    }
    return NULL;
}

void archer_nme_ns::ChaseState::exit(ArcherEnemy& archerEnemy)
{

}

void archer_nme_ns::AttackState::enter(ArcherEnemy& archerEnemy)
{

}

archer_nme_ns::ArcherEnemyState* archer_nme_ns::AttackState::update(ArcherEnemy& archerEnemy)
{
    archerEnemy.getSprite()->setVelocity(0, 0);
    // archerEnemy.innerBox->setVelocity(0, 0);
    return NULL;
}

void archer_nme_ns::AttackState::exit(ArcherEnemy& archerEnemy)
{
    
}

void archer_nme_ns::IdleState::enter(ArcherEnemy& archerEnemy)
{

}

archer_nme_ns::ArcherEnemyState* archer_nme_ns::IdleState::update(ArcherEnemy& archerEnemy)
{
    return NULL;
}

void archer_nme_ns::IdleState::exit(ArcherEnemy& archerEnemy)
{

}