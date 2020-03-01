#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gbavector.h>
#include <tonc_math.h>
#include <deque>
// #include "entity.h"
#include "player.h"
#include "collisionBox.h"

class EnemyState;

class Enemy : public Entity
{
private:
    VECTOR dest;
    std::deque<VECTOR> destCoords;
protected:
    int fuel{5};
    int actionDistancex{1};
    int actionDistancey{4};

public:
    Enemy(int x, int y);
    
    EnemyState* state;
    RECT* playerVicinity;
    RECT* myBoundingBox;
    std::unique_ptr<CollisionBox> innerBox;
    void tick();
    void setPlayerPos(VECTOR destination);
    VECTOR getPlayerPos() {return dest; }
    int getFuel() { return fuel; }
    int getActionDistanceX() { return actionDistancex; }
    int getActionDistanceY() { return actionDistancey; }

    Sprite* getSprite() { return Entity::getSprite(); }
    std::deque<VECTOR>& getDestCoords() { return destCoords; }
};

class EnemyState
{
public:
    int stateId;
    virtual ~EnemyState() {}
    virtual void enter(Enemy& enemy) {}
    virtual EnemyState* update(Enemy& enemy) { return new EnemyState; }
    virtual void exit(Enemy& enemy) {}
};

class IdleStateShield : public EnemyState
{
public:
    ~IdleStateShield() {}
    void enter(Enemy& enemy);
    EnemyState* update(Enemy& enemy);
    void exit(Enemy& enemy);
};

class ChaseState : public EnemyState
{
public:
    ~ChaseState() {}
    void enter(Enemy& enemy);
    EnemyState* update(Enemy& enemy);
    void exit(Enemy& enemy);
    
};

class AttackState : public EnemyState
{
public:
    ~AttackState() {}
    void enter(Enemy& enemy);
    EnemyState* update(Enemy& enemy);
    void exit(Enemy& enemy);
};


#endif