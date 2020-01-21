#ifndef __DEMO_SCENE_H__
#define __DEMO_SCENE_H__

#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>


class DemoScene : public Scene
{
private:
    std::unique_ptr<Background> background;


public:
    explicit DemoScene(const std::shared_ptr<GBAEngine> &engine);
    DemoScene(DemoScene &other) = delete;
    void tick(u16 keys) override;
    void load() override;

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;

};


#endif