#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gba_engine.h>
// instead of using inheritance like in phaser sprites, we use composition and include a Sprite in our enemy class
//Enemy 'has a' sprite
#include "combined.h"

class Entity 
{

private:
    
    std::unique_ptr<Sprite> sprite;
    enum fDirection {LEFT, RIGHT, UP, DOWN};

protected:
    SpriteBuilder<Sprite> spriteBuilder;
    int x;
    int y;
    int movementSpeed = 1;
    int health{ 100 };

public:
    Entity(int x, int y) : x(x), y(y) {}

    int faceDirection;
    virtual void tick() = 0;

    void setMovementSpeed(int s) { movementSpeed = s; }
    int getMovementSpeed() { return movementSpeed; }
    void setHealth(int x) { health = x; }
    int getHealth() { return health; }
    Sprite* getSprite() { return sprite.get(); }
    void setSprite(std::unique_ptr<Sprite> sprite);


};






#endif