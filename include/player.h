#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/timer.h>
#include "entity.h"

class Player : public Entity
{
private :
    u16 key;
    bool canReadInput = true;
    enum fDirection {LEFT, RIGHT, UP, DOWN};
    std::unique_ptr<Timer> dashTimer;

protected :
    int faceDirection = fDirection::DOWN;

public:
    Player(int x, int y);
    void tick();
    void readInput(u16 keys);
    void dash(u16 keys);
    void walk(u16 keys);
    Sprite* getSprite() { return Entity::getSprite(); }
    int getFaceDirection() { return faceDirection; }
};





#endif  