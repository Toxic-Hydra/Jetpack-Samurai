#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "demo_scene.h"
#include "jscomp16.h"

#include <typeinfo>

static int bufferFrames = 0;

DemoScene::DemoScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> DemoScene::backgrounds()
{
    return {};
}

std::vector<Sprite *> DemoScene::sprites()
{
    spriteVector.clear(); //we shove all our sprites into this

    spriteVector.push_back(player->getSprite());
    spriteVector.push_back(enemy->getSprite());
    spriteVector.push_back(player->playerAttackSprite.get());

    return spriteVector;
}

void DemoScene::tick(u16 keys)
{
    //We will eventually need to implement a way to keep track of how many enemies are in the scene for this.
    if(spriteVector.size() != 3) //If the vector does not contain the proper amount of sprites, rebuild.
    {
        engine->updateSpritesInScene();
    }
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

    if(keys & KEY_START) // Reset Health
    {
        player->setHealth(100);
    }


    // UI
    if(player->getHealth() <= 10)
    {
        TextStream::instance().setFontColor(CLR_RED);
    }
    else
    {
        TextStream::instance().setFontColor(CLR_WHITE);
    }
    TextStream::instance().setText("Fuel: " + std::to_string(player->getHealth()), 0, 0);
    // TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10); // Debug info for player direction


    // Collision Checking
    if (player->playerAttackSprite->collidesWith(*enemy->getSprite()))
    {
        enemy->getSprite()->moveTo(-100,0);
        //TextStream::instance() << engine->getTimer()->getSecs();
    }
    if (player->getSprite()->collidesWith(*enemy->getSprite()))
    {
        player->useFuel(1);
    }
}

void DemoScene::load()
{
    
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    player = std::unique_ptr<Player>(new Player(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32));
    player->getSprite()->stopAnimating();
    player->setHealth(100);
    //TextStream::instance() << player->getFaceDirection();
    // player->setMovementSpeed(10); // uncomment this for blazing fast speeds
    enemy = std::unique_ptr<Enemy>(new Enemy(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32));
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    engine->getTimer()->start();

    
}
