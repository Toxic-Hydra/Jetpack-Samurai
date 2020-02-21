#ifndef __COLLISION_BOX_H__
#define __COLLISION_BOX_H__

#include <tonc_math.h>

class CollisionBox
{
private:
    RECT box;
public:
    CollisionBox(int x, int y, int width, int height);
    ~CollisionBox();

    bool collidesWith(CollisionBox &otherBox);

    // Setters
    void setX(int x) { box.left = x; }
    void setY(int y) { box.top = y; }
    void setWidth(int width) { box.right = box.left + width; }
    void setHeight(int height) { box.bottom = box.top + height; }

    // Getters
    int getX() { return box.left; }
    int getY() { return box.top; }
    int getWidth() { return rc_width(&box); }
    int getHeight() { return rc_height(&box); }
};

#endif