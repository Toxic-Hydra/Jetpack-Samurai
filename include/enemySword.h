#ifndef __ENEMYSWORD_H__
#define __ENEMYSWORD_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/gbavector.h>
#include <tonc_math.h>
#include <libgba-sprite-engine/timer.h>
#include <deque>
// #include "entity.h"
#include "player.h"
#include "collisionBox.h"

class EnemySwordState;

class EnemySword : public Entity
{
private:
    VECTOR dest;
    std::deque<VECTOR> destCoords;
    int actionDistx{42};
    int actionDisty{42};
    std::unique_ptr<Timer> atkTimer{std::make_unique<Timer>()};
    int atkWait{600};
    //std::unique_ptr<Sprite> atkSprite;
    
protected:
    
    

public:
    EnemySword(int x, int y);
    std::unique_ptr<Sprite> swordAttackSprite = (spriteBuilder
                    .withData(swordAttackTiles, sizeof(swordAttackTiles))
                    .withSize(SIZE_16_32))
                    .withAnimated(3, 3)
                    .withLocation(-100,-100)
                    .buildPtr();
    
    EnemySwordState* state;
    RECT* playerVicinity;
    RECT* myBoundingBox; 
    std::unique_ptr<CollisionBox> innerBox;
    void tick();
    void setPlayerPos(VECTOR destination);
    VECTOR getPlayerPos() {return dest; }
    int getActionDistanceX() {return actionDistx; }
    int getActionDistanceY() { return actionDisty; }
    int getAtkWait(){return atkWait;}

    Sprite* getSprite() { return Entity::getSprite(); }
    std::deque<VECTOR>& getDestCoords() { return destCoords; }
    Timer* getAtkTimer() { return atkTimer.get(); }
};

class EnemySwordState
{
public:
    int stateID = 0;
    virtual ~EnemySwordState() {}
    virtual void enter(EnemySword& enemy) {}
    virtual EnemySwordState* update(EnemySword& enemy) { return new EnemySwordState; }
    virtual void exit(EnemySword& enemy) {}
};

class SwordChaseState : public EnemySwordState
{
public:
    SwordChaseState() { stateID = 1; }
    ~SwordChaseState() {}
    void enter(EnemySword& enemy);
    EnemySwordState* update(EnemySword& enemy);
    void exit(EnemySword& enemy);
    
};

class SwordAttackState : public EnemySwordState
{
public:
    SwordAttackState() { stateID = 2; }
    ~SwordAttackState() {}
    void enter(EnemySword& enemy);
    EnemySwordState* update(EnemySword& enemy);
    void exit(EnemySword& enemy);
};

class SwordIdleState : public EnemySwordState
{
public:
    SwordIdleState() { stateID = 3; }
    ~SwordIdleState() {}
    void enter(EnemySword& enemy);
    EnemySwordState* update(EnemySword& enemy);
    void exit(EnemySword& enemy);
};

class SwordRetreatState : public EnemySwordState
{
public:
    SwordRetreatState() { stateID = 4; }
    ~SwordRetreatState() {}
    void enter(EnemySword& enemy);
    EnemySwordState* update(EnemySword& enemy);
    void exit(EnemySword& enemy);
};







#endif