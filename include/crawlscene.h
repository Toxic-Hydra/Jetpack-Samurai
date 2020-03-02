#ifndef __CRAWL_SCENE_H__
#define __CRAWL_SCENE_H__
#include <libgba-sprite-engine/scene.h>
#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/background/text_stream.h>

#include "demo_scene.h"
#include "startscene.h"



class CrawlScene : public Scene
{
private:
    std::string pressStart;
    std::unique_ptr<Background> crawlText;
    int x;
public:
    CrawlScene(std::shared_ptr<GBAEngine> engine) : Scene(std::move(engine)) {}
    void tick(u16 keys) override;
    void load() override;
    std::vector<Sprite *> sprites() override;
    std::vector<Background *> backgrounds() override;
};



#endif