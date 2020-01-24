#include "test_entity.h"

TestEntity::TestEntity(int x, int y) : Entity(x, y)
{
    this->setSprite((spriteBuilder
                    .withData(avatar_data, sizeof(avatar_data))
                    .withSize(SIZE_64_64))
                    .withLocation(x,y)
                    .buildPtr());
}