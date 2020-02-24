#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_math.h>

#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "collisionBox.h"


class DemoScene : public Scene
{
private:
    std::unique_ptr<SpriteManager> spriteManager;
    std::unique_ptr<Background> background;
    std::unique_ptr<Player> player;
    std::unique_ptr<Enemy> enemy;

    std::vector<Sprite*> spriteVector;

    Sprite* playerSprite;
    // u32 playerLeft, playerRight, playerTop, playerBottom;
    // u32 enemyLeft, enemyRight, enemyTop, enemyBottom;

    // Bounding Box Test
    std::unique_ptr<CollisionBox> playerBox;
    std::unique_ptr<CollisionBox> innerPlayerBox;
    std::unique_ptr<CollisionBox> enemyBox;
    std::unique_ptr<CollisionBox> innerEnemyBox;
public:
    explicit DemoScene(const std::shared_ptr<GBAEngine> &engine);
    //DemoScene(DemoScene &other) = delete;
    void tick(u16 keys) override;
    void load() override;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

};


#endif