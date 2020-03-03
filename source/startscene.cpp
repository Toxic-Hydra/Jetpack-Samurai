#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "startscene.h"
#include "demo_scene.h"

void StartScene::tick(u16 keys)
{
    if (keys & KEY_START)
    {
        // engine->setScene(new DemoScene(std::move(engine)));
        if(!engine->isTransitioning())
        {
            engine->transitionIntoScene(new DemoScene(std::move(engine)), new FadeOutScene(2));
        }
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
    // foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
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