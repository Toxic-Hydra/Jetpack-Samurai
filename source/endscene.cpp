#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/effects/fade_out_scene.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <tonc_memdef.h>

#include "endscene.h"
#include "startscene.h"

void EndScene::tick(u16 keys)
{
    if (keys & KEY_SELECT)
    {
        // engine->setScene(new DemoScene(std::move(engine)));
        if(!engine->isTransitioning())
        {
            engine->transitionIntoScene(new StartScene(std::move(engine)), new FadeOutScene(2));
        }
    }
}

void EndScene::load()
{
    engine->enableText();
    TextStream::instance().setText("Geemu Obaa", 6, 9);
}

std::vector<Sprite *> EndScene::sprites()
{
    // If player is of type: std::unique_ptr<Player>
    // return { player->getSprite() }; // Uncommenting this crashes mGBA

    // If player is of type: std::unique_ptr<Sprite>
    // return { player.get() }; // Uncommenting this sets the scene to StartScene for some reason
    return {};
}

std::vector<Background *> EndScene::backgrounds()
{
    return {};
}