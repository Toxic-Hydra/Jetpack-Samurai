#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
// instead of using inheritance like in phaser sprites, we use composition and include a Sprite in our enemy class
//Enemy 'has a' sprite
#include "combined.h"

class Entity 
{

private:
    
    std::unique_ptr<Sprite> sprite;

protected:
    SpriteBuilder<Sprite> spriteBuilder;
    int x;
    int y;
    int health{ 100 };

public:
    Entity(int x, int y) : x(x), y(y) {}

    virtual void tick() = 0;

    void setHealth(int x) { health = x; }
    int getHealth() { return health; }
    Sprite* getSprite() { return sprite.get(); }
    void setSprite(std::unique_ptr<Sprite> sprite);


};






#endif