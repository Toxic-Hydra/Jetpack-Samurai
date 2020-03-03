#ifndef __END_SCENE_H__
#define __END_SCENE_H__
#include <libgba-sprite-engine/scene.h>

class EndScene : public Scene
{
private:
    // std::unique_ptr<Sprite> player;
public:
    EndScene(std::shared_ptr<GBAEngine> engine) : Scene(std::move(engine)) {}
    EndScene(EndScene &other) = delete;
    void tick(u16 keys) override;
    void load() override;
    

    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
};





#endif