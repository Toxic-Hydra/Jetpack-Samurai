#ifndef __TEST_ENTITY_H__
#define __TEST_ENTITY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "entity.h"

class TestEntity : public Entity
{
public:
    TestEntity(int x, int y);
    

    void tick() {}

    Sprite* getSprite() { return Entity::getSprite(); }
};



#endif