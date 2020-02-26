#include "endscene.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
// #include "demo_scene.h"
#include "startscene.h"

void EndScene::tick(u16 keys)
{
    
    if (keys & KEY_L)
    {
        engine->setScene(new StartScene(engine));
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