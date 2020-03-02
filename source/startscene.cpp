#include "startscene.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "crawlscene.h"

void StartScene::tick(u16 keys)
{
    if(keys == KEY_START)
    {
        // TextStream::instance().clear(); // This does not seem to clear "Press Start"
        // engine->disableText();
        engine->setScene(new CrawlScene(std::move(engine)));
    }

    if (engine->getTimer()->getSecs() % 3 == 0)
    {
        pressStart = "";
    }
    else
    {
        pressStart = "Press Start";
    }
    TextStream::instance().setText(pressStart, 10, 9);
}

void StartScene::load()
{
    engine->enableText();
    TextStream::instance().setText("Jetpack Samurai", 6, 7);
    pressStart = "Press Start";
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