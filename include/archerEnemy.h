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

namespace archer_nme_ns
{
    class ArcherEnemyState;
    class ChaseState;
    class AttackState;
    class IdleState;
}

class ArcherEnemy : public Entity
{
private:
    VECTOR dest;
    std::deque<VECTOR> destCoords;
protected:
    
    

public:
    ArcherEnemy(int x, int y);
    
    archer_nme_ns::ArcherEnemyState* state;
    RECT* playerVicinity;
    RECT* myBoundingBox; 
    std::unique_ptr<CollisionBox> innerBox;
    void tick();
    void setPlayerPos(VECTOR destination);
    VECTOR getPlayerPos() {return dest; }

    Sprite* getSprite() { return Entity::getSprite(); }
    std::deque<VECTOR>& getDestCoords() { return destCoords; }
};

class archer_nme_ns::ArcherEnemyState
{
public:
    virtual ~ArcherEnemyState() {}
    virtual void enter(ArcherEnemy& archerEnemy) {}
    virtual archer_nme_ns::ArcherEnemyState* update(ArcherEnemy& archerEnemy) { return new archer_nme_ns::ArcherEnemyState; }
    virtual void exit(ArcherEnemy& archerEnemy) {}
};

class archer_nme_ns::ChaseState : public ArcherEnemyState
{
public:
    ~ChaseState() {}
    void enter(ArcherEnemy& archerEnemy);
    archer_nme_ns::ArcherEnemyState* update(ArcherEnemy& archerEnemy);
    void exit(ArcherEnemy& archerEnemy);
    
};

class archer_nme_ns::IdleState : public ArcherEnemyState
{
public:
    ~IdleState() {}
    void enter(ArcherEnemy& archerEnemy);
    archer_nme_ns::ArcherEnemyState* update(ArcherEnemy& archerEnemy);
    void exit(ArcherEnemy& archerEnemy);
    
};

class archer_nme_ns::AttackState : public ArcherEnemyState
{
public:
    ~AttackState() {}
    void enter(ArcherEnemy& archerEnemy);
    archer_nme_ns::ArcherEnemyState* update(ArcherEnemy& archerEnemy);
    void exit(ArcherEnemy& archerEnemy);
};






#endif