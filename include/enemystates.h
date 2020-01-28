#ifndef __ENEMYSTATE_H__
#define __ENEMYSTATE_H__

#include "enemy.h"
//to avoid cyclical includes might as well just include this in enemy.h

class EnemyState
{
    public:
    virtual ~EnemyState() {}
    virtual void update(Enemy& enemy) {}
    virtual void enter(Enemy& enemy) {}
    virtual void exit(Enemy& enemy) {}
}




#endif