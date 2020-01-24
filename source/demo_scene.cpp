#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <algorithm>
#include <libgba-sprite-engine/background/text_stream.h>
#include <sstream>
#include "demo_scene.h"

DemoScene::DemoScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> DemoScene::backgrounds()
{
    return {};
}

std::vector<Sprite *> DemoScene::sprites()
{
    std::vector<Sprite*> sprites; //we shove all our sprites into this

    sprites.push_back(avatar->getSprite());

    return sprites;
}

void DemoScene::tick(u16 keys)
{

}

void DemoScene::load()
{
    TextStream::instance() << "woah";
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(avatar_palette, sizeof(avatar_palette)));

    avatar = std::unique_ptr<TestEntity>(new TestEntity(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32));
    

}