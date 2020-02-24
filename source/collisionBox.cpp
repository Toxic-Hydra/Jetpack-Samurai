#include "collisionBox.h"

CollisionBox::CollisionBox(int x, int y, int width, int height)
{
    rc_set2(&box, x, y, width, height);
}

bool CollisionBox::collidesWith(CollisionBox &otherBox)
{
    if (box.left < otherBox.right &&
        box.right > otherBox.left &&
        box.top < otherBox.bottom &&
        box.bottom > otherBox.top)
    {
        // Move both boxes depending on relative forces (velocity x mass)
        // Code here
        //
        /////////////////////////////////////////////////////////////////
        return true;
    }
    return false;
}