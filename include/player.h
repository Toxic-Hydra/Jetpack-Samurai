#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/sprites/sprite.h>
#include <libgba-sprite-engine/timer.h>
#include "entity.h"

// Player namespace so that there are no conflicts
// with states that share the same name as enemy states
namespace player_ns
{
    class PlayerState;
    class UnrestrictedState;
    class DamagedState;
    class AttackState;
    class DashState;
    class BlockState;
}

class Player : public Entity
{
private :
    // static int frames;
    // int bufferWindow = 3; // Number of frames elapsed until checking the next input, key, states
    u16 keyPrev;
    u16 key; // the current key
    // enum fDirection {LEFT, RIGHT, UP, DOWN};
    static std::unique_ptr<Timer> dashTimer;
    int dashSpeed{8};

protected :
    

public:
    Player(int x, int y);
    std::unique_ptr<Sprite> playerAttackSprite = (spriteBuilder
                    .withData(Attack_Right_p2Tiles, sizeof(Attack_Right_p2Tiles))
                    .withSize(SIZE_16_32))
                    .withAnimated(8, 3)
                    .withLocation(-100,-100)
                    .buildPtr();
    std::unique_ptr<Sprite> attackBottom = (spriteBuilder
                    .withData(attackBottomTiles, sizeof(attackBottomTiles))
                    .withSize(SIZE_32_16))
                    .withLocation(-100,-100)
                    .buildPtr();
    // int faceDirection = fDirection::RIGHT;
    player_ns::PlayerState* state = NULL;
    void tick();
    void useFuel(int x);
    void playerAttack();
    u32 keyHit(u16 keys);
    void readInput(u16 keys);
    void dash();
    void walk();
    void lockMovement();
    Sprite* getSprite() { return Entity::getSprite(); }
    Timer* getDashTimer() { return dashTimer.get(); }
    u16 getKey() { return key; }
    int getFaceDirection() { return faceDirection; }
    int getDashSpeed() { return dashSpeed; }
};

class player_ns::PlayerState
{
public:
    int stateID = 0;
    std::unique_ptr<SpriteBuilder<Sprite>> spriteBuilder;
    virtual ~PlayerState() {}
    virtual void enter(Player& player) {}
    virtual player_ns::PlayerState* update(Player& player) { return new player_ns::PlayerState; }
    virtual void exit(Player& player) {}
    bool operator==(player_ns::PlayerState const &otherState)
    {
        return (stateID = otherState.stateID);
    }
};

class player_ns::UnrestrictedState : public PlayerState
{
public:
    // int stateID = 1;
    UnrestrictedState() { stateID = 1; }
    ~UnrestrictedState() {}
    void enter(Player& player);
    player_ns::PlayerState* update(Player& player);
    void exit(Player& player);
};

class player_ns::DamagedState : public PlayerState
{
private:
    int damage;
    int dx_, dy_;
public:
    // int stateID = 2;
    DamagedState() { stateID = 2; }
    DamagedState(int dmg, int dx, int dy);
    ~DamagedState() {}
    void enter(Player& player);
    player_ns::PlayerState* update(Player& player);
    void exit(Player& player);
};

class player_ns::AttackState : public PlayerState
{
public:
    // int stateID = 3;
    AttackState() { stateID = 3; }
    ~AttackState() {}
    void enter(Player& player);
    player_ns::PlayerState* update(Player& player);
    void exit(Player& player);
};

class player_ns::DashState : public PlayerState
{
public:
    // int stateID = 4;
    DashState() { stateID = 4; }
    ~DashState() {}
    void enter(Player& player);
    player_ns::PlayerState* update(Player& player);
    void exit(Player& player);
};

class player_ns::BlockState : public PlayerState
{
public:
    // int stateID = 5;
    BlockState() { stateID = 5; }
    ~BlockState() {}
    void enter(Player& player);
    player_ns::PlayerState* update(Player& player);
    void exit(Player& player);
};

#endif  