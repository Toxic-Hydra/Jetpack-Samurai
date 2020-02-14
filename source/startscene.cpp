#include "startscene.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "demo_scene.h"

void StartScene::tick(u16 keys)
{
    if(keys == KEY_START)
    {
        // TextStream::instance().clear(); // This does not seem to clear "Press Start"
        // engine->disableText();
        engine->setScene(new DemoScene(std::move(engine)));
    }

    std::string pressStart = "Press Start";
    if (engine->getTimer()->getSecs() % 3 == 0)
    {
        pressStart = "";
    }
    TextStream::instance().setText(pressStart, 10, 9);
}

void StartScene::load()
{
    engine->enableText();
    TextStream::instance().setText("Jetpack Samurai", 6, 7);
    engine->getTimer()->start();
}

std::vector<Sprite *> StartScene::sprites()
{
    return {};
}

std::vector<Background *> StartScene::backgrounds()
{
    return {};
}