#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "entity.h"

class EnemyState;

class Enemy : public Entity
{
public:
    Enemy(int x, int y);
    
    EnemyState* state;
    void tick();

    Sprite* getSprite() { return Entity::getSprite(); }
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