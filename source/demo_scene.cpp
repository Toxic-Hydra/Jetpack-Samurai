#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <algorithm>
#include <libgba-sprite-engine/background/text_stream.h>
#include <sstream>
#include "demo_scene.h"

static int bufferFrames = 0;

DemoScene::DemoScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> DemoScene::backgrounds()
{
    return {};
}

std::vector<Sprite *> DemoScene::sprites()
{
    std::vector<Sprite*> sprites; //we shove all our sprites into this

    sprites.push_back(player->getSprite());
    sprites.push_back(enemy->getSprite());
    sprites.push_back(player->playerAttackSprite.get());

    return sprites;
}

void DemoScene::tick(u16 keys)
{
    // Enemy
    enemy->setPlayerPos(player->getSprite()->getPos());
    enemy->tick();


    // Player

    // Not sure how to do this, but I wish to implement some sort of input leniency
    // in case players cannot tap a button for exactly one frame. This was my best
    // attempt.
    // - Charles
    if(bufferFrames % 5 == 0)
    {
        player->readInput(keys); // Read input every 5 frames
    }
    bufferFrames++;
    player->tick();


    // UI
    TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10);


    // Collision Checking
    if (player->playerAttackSprite->collidesWith(*enemy->getSprite()))
    {
        TextStream::instance() << "yep";
    }
}

void DemoScene::load()
{
    
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    player = std::unique_ptr<Player>(new Player(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32));
    player->getSprite()->stopAnimating();
    //TextStream::instance() << player->getFaceDirection();
    // player->setMovementSpeed(10); // uncomment this for blazing fast speeds
    enemy = std::unique_ptr<Enemy>(new Enemy(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32));
    

}