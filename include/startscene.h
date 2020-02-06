#ifndef __START_SCENE_H__
#define __START_SCENE_H__
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "demo_scene.h"


class StartScene : public Scene
{
public:
    StartScene(std::shared_ptr<GBAEngine> engine) : Scene(std::move(engine)) {}
    void tick(u16 keys) override;
    void load() override;
    

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
};





#endif