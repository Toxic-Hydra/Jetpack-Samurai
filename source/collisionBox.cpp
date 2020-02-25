#include "collisionBox.h"

CollisionBox::CollisionBox(int x, int y, int width, int height)
{
    dx_ = 0;
    dy_ = 0;
    box = new RECT;
    rc_set2(box, x, y, width, height);
}

CollisionBox::~CollisionBox()
{
    
}

bool CollisionBox::collidesWith(CollisionBox &otherBox)
{
    if (box->left < otherBox.getX() + otherBox.getWidth() &&
        box->right > otherBox.getX() &&
        box->top < otherBox.getY() + otherBox.getHeight() &&
        box->bottom > otherBox.getY())
    {
        // Move both boxes depending on relative forces (velocity x mass)
        // Code here
        //
        /////////////////////////////////////////////////////////////////

        // For now, each collision box will have mass = 1
        // So just look @ the else block until then
        if (this->mass < otherBox.mass)
        {

        }
        else if (this->mass > otherBox.mass)
        {

        }
        else
        {
            // Bounce this box
            rc_move(box, otherBox.getDx(), otherBox.getDy());
            
            // Bounce the other box
            rc_move(otherBox.box, dx_, dy_);
        }
        return true;
    }
    return false;
}

bool CollisionBox::collidesWith(Sprite& otherSprite)
{
    if(box->left < otherSprite.getX() + otherSprite.getWidth() &&
       box->right > otherSprite.getX() &&
       box->top < otherSprite.getY() + otherSprite.getHeight() &&
       box->bottom > otherSprite.getY())
    {
        // Bounce this box
        rc_move(box, (int)otherSprite.getDx(), (int)otherSprite.getDy());
        return true;
    }
    return false;
}