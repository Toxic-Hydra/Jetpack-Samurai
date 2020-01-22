#ifndef __ENTITY_H__
#define __ENTITY_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
// instead of using inheritance like in phaser sprites, we use composition and include a Sprite in our enemy class
//Enemy 'has a' sprite

class Entity 
{

private:
    int health{ 100 };
    std::unique_ptr<Sprite> sprite;


public:
    Entity(std::unique_ptr<Sprite> sprite) : sprite(std::move(sprite)) {}

    virtual void tick() = 0;

    void setHealth(int x) { health = x; }
    int getHealth() { return health; }
    Sprite* getSprite() { return sprite.get(); }


};






#endif