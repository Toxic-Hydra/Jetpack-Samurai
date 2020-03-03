#ifndef __START_SCENE_H__
#define __START_SCENE_H__
#include <libgba-sprite-engine/scene.h>

class StartScene : public Scene
{
public:
    StartScene(std::shared_ptr<GBAEngine> engine) : Scene(std::move(engine)) {}
    StartScene(StartScene &other) = delete;
    void tick(u16 keys) override;
    void load() override;
    

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
};





#endif