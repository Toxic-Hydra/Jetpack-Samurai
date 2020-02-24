#ifndef __COLLISION_BOX_H__
#define __COLLISION_BOX_H__

#include <tonc_math.h>

class CollisionBox
{
private:
    RECT* box;
    int mass = 1;
    int dx_, dy_;
public:
    CollisionBox(int x, int y, int width, int height);
    ~CollisionBox();

    bool collidesWith(CollisionBox &otherBox);

    // Setters
    void setPos(int x, int y)
    {
        box->right += x - box->left;	box->left= x;
	    box->bottom += y - box->top;	box->top= y;
    }
    void setWidth(int width)
    {
        box->right = box->left + width;
    }
    void setHeight(int height)
    {
        box->bottom = box->top + height;
    }
    void setDx(int dx) { dx_ = dx; }
    void setDy(int dy) { dy_ = dy; }
    void setVelocity(int dx, int dy)
    {
        dx_ = dx;
        dy_ = dy;
    }
    void move(int dx, int dy)
    {
        box->left += dx;	box->top += dy;
	    box->right += dx;	box->bottom += dy;
    }

    // Getters
    int getX() { return box->left; }
    int getY() { return box->top; }
    int getWidth() { return rc_width(box); }
    int getHeight() { return rc_height(box); }
    int getDx() { return dx_; }
    int getDy() { return dy_; }
};

#endif