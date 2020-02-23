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
    std::unique_ptr<Sprite> playerAttackSprite = (spriteBuilder
                    .withData(asamuraiTiles, 2048)
                    .withSize(SIZE_16_32))
                    //.withAnimated(4, 3)
                    .withLocation(-100,-100)
                    .buildPtr();;
    void tick();
    void useFuel(int x);
    void playerAttack();
    u32 keyHit(u16 keys);
    void readInput(u16 keys);
    void dash();
    void walk();
    Sprite* getSprite() { return Entity::getSprite(); }
    int getFaceDirection() { return faceDirection; }
    u16 getKey() { return key; };
};





#endif  