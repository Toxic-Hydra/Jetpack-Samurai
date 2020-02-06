#include "startscene.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "demo_scene.h"

void StartScene::tick(u16 keys)
{
    if(keys == KEY_START)
    {
        
        engine->setScene(new DemoScene(std::move(engine)));
    }
}

void StartScene::load()
{
    engine->enableText();
    TextStream::instance() << "Jetpack Samurai";
}

std::vector<Sprite *> StartScene::sprites()
{
    return {};
}

std::vector<Background *> StartScene::backgrounds()
{
    return {};
}