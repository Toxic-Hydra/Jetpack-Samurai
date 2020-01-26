#ifndef __ENEMY_H__
#define __ENEMY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "entity.h"

class Enemy : public Entity
{
public:
    Enemy(int x, int y);
    

    void tick() {}

    Sprite* getSprite() { return Entity::getSprite(); }
};





#endif