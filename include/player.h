#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/timer.h>
#include "entity.h"

class Player : public Entity
{
private :
    static int frames;
    int bufferWindow = 3; // Number of frames elapsed until checking the next input, key, states
    u16 keyPrev;
    u16 key; // the current key
    enum fDirection {LEFT, RIGHT, UP, DOWN};
    std::unique_ptr<Timer> dashTimer;

protected :
    int faceDirection = fDirection::RIGHT;

public:
    Player(int x, int y);
    void tick();
    u32 keyHit(u16 keys);
    void readInput(u16 keys);
    void dash(u16 keys);
    void walk(u16 keys);
    Sprite* getSprite() { return Entity::getSprite(); }
    int getFaceDirection() { return faceDirection; }
};





#endif  