#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "entity.h"

class Player : public Entity
{
public:
    Player(int x, int y);
    void tick() {}
    void moveWithDPad(u16 keys);
    Sprite* getSprite() { return Entity::getSprite(); }
};





#endif