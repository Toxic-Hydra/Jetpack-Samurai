#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gbavector.h>
#include <tonc_math.h>
#include <deque>
#include "entity.h"

class EnemyState;

class Enemy : public Entity
{
private:
    VECTOR dest;
    std::deque<VECTOR> destCoords;
    
protected:
    
    

public:
    Enemy(int x, int y);
    
    EnemyState* state;
    void tick();
    void setPlayerPos(VECTOR destination);
    VECTOR getPlayerPos() {return dest; }

    Sprite* getSprite() { return Entity::getSprite(); }
    std::deque<VECTOR>& getDestCoords() { return destCoords; }
};

class EnemyState
{
    public:
    virtual ~EnemyState() {}
    virtual void enter(Enemy& enemy) {}
    virtual void update(Enemy& enemy) {}
    virtual void exit(Enemy& enemy) {}
};

class ChaseState : public EnemyState
{
    public:
    ~ChaseState() {}
    void enter(Enemy& enemy);
    void update(Enemy& enemy);
    void exit(Enemy& enemy);
    
};








#endif