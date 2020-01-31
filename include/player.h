#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include "entity.h"

class Player : public Entity
{
private :
    enum fDirection {LEFT, RIGHT, UP, DOWN};

protected :
    int faceDirection = fDirection::DOWN;

public:
    Player(int x, int y);
    std::unique_ptr<Sprite> playerAttackSprite = (spriteBuilder
                    .withData(playerTiles, sizeof(playerTiles))
                    .withSize(SIZE_16_32))
                    //.withAnimated(4, 3)
                    .withLocation(-100,-100)
                    .buildPtr();;
    void tick() {}
    void moveWithDPad(u16 keys);
    void playerAttack(u16 keys);
    Sprite* getSprite() { return Entity::getSprite(); }
    int getFaceDirection() { return faceDirection; }
};





#endif  