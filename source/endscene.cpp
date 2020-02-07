#include "endscene.h"
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "demo_scene.h"

void EndScene::tick(u16 keys)
{

}

void EndScene::load()
{
    engine->enableText();
    TextStream::instance().setText("Geemu Obaa", 6, 9);
}

std::vector<Sprite *> EndScene::sprites()
{
    return {};
}

std::vector<Background *> EndScene::backgrounds()
{
    return {};
}