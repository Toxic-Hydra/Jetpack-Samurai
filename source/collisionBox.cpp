#include "collisionBox.h"

CollisionBox::CollisionBox(int x, int y, int width, int height)
{
    rc_set2(&box, x, y, width, height);
}

bool CollisionBox::collidesWith(CollisionBox &otherBox)
{
    return false;
}