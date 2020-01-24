#include "entity.h"

void Entity::setSprite(std::unique_ptr<Sprite> sprite)
{
    Entity::sprite = std::move(sprite);
}