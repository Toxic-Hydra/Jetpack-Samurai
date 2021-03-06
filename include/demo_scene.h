#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include <libgba-sprite-engine/scene.h>

#include "entity.h"
#include "player.h"
#include "archerEnemy.h"
#include "enemySword.h"

// #include "collisionBox.h"


class DemoScene : public Scene
{
private:
    std::unique_ptr<SpriteManager> spriteManager;
    std::unique_ptr<Background> background;
    std::unique_ptr<Player> player;
    std::unique_ptr<EnemySword> enemy;


    std::vector<Sprite*> spriteVector;

    Sprite* playerSprite;
    // u32 playerLeft, playerRight, playerTop, playerBottom;
    u32 enemyLeft, enemyRight, enemyTop, enemyBottom;
    int tile_collide;
    int border = 40;
    unsigned int nBSSongSize;
    int scrollx{0}, scrolly{0};
public:
    explicit DemoScene(const std::shared_ptr<GBAEngine> &engine);
    //DemoScene(DemoScene &other) = delete;
    void tick(u16 keys) override;
    void load() override;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

};


#endif