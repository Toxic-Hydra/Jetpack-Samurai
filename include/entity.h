#ifndef __ENTITY_H__
#define __ENTITY_H__

// instead of using inheritance like in phaser sprites, we use composition and include a Sprite in our enemy class
//Enemy 'has a' sprite

class Entity 
{
public:
    std::unique_ptr<Sprite> sprite;

private:


};






#endif