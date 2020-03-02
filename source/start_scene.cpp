#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>

#include "start_scene.h"
#include "demo_scene.h"

// StartScene::StartScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> StartScene::backgrounds()
{
    return {};
}

std::vector<Sprite *> StartScene::sprites()
{
    std::vector<Sprite*> sprites; //we shove all our sprites into this
    // spriteVector.clear();

    return sprites;
}

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

    // if (engine->getTimer()->getSecs() % 3 == 0)
    // {
    //     pressStart = "Press Start";
    // }
    // else
    // {
    //     pressStart = "";
    // }
    TextStream::instance().setText(pressStart, 5, 10);
}

void StartScene::load()
{
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    pressStart = "Press Start";
    engine->getTimer()->start();
}
