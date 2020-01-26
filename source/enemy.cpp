#include "enemy.h"

Enemy::Enemy(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(tryenemyTiles, sizeof(tryenemyTiles))
                    .withSize(SIZE_16_32))
                    .withLocation(x,y)
                    .buildPtr());
}