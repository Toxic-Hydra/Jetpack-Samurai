#ifndef __ARCHER_ENEMY_H__
#define __ARCHER_ENEMY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gbavector.h>
#include <tonc_math.h>
#include <deque>
// #include "entity.h"
#include "player.h"
#include "collisionBox.h"

class ArcherEnemyState;

class ArcherEnemy : public Entity
{
private:
    VECTOR dest;
    std::deque<VECTOR> destCoords;
protected:
    
    

public:
    ArcherEnemy(int x, int y);
    
    ArcherEnemyState* state;
    RECT* playerVicinity;
    RECT* myBoundingBox; 
    std::unique_ptr<CollisionBox> innerBox;
    void tick();
    void setPlayerPos(VECTOR destination);
    VECTOR getPlayerPos() {return dest; }

    Sprite* getSprite() { return Entity::getSprite(); }
    std::deque<VECTOR>& getDestCoords() { return destCoords; }
};

class ArcherEnemyState
{
public:
    virtual ~ArcherEnemyState() {}
    virtual void enter(ArcherEnemy& archerEnemy) {}
    virtual ArcherEnemyState* update(ArcherEnemy& archerEnemy) { return new ArcherEnemyState; }
    virtual void exit(ArcherEnemy& archerEnemy) {}
};

class ChaseState : public ArcherEnemyState
{
public:
    ~ChaseState() {}
    void enter(ArcherEnemy& archerEnemy);
    ArcherEnemyState* update(ArcherEnemy& archerEnemy);
    void exit(ArcherEnemy& archerEnemy);
    
};

class AttackState : public ArcherEnemyState
{
public:
    ~AttackState() {}
    void enter(ArcherEnemy& archerEnemy);
    ArcherEnemyState* update(ArcherEnemy& archerEnemy);
    void exit(ArcherEnemy& archerEnemy);
};






#endif