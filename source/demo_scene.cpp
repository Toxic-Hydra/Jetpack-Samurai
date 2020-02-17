#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "map32.h"
#include "demo_scene.h"
#include "jscomp16.h"

static int bufferFrames = 0;

DemoScene::DemoScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> DemoScene::backgrounds()
{
    return {
        background.get()
    };
}

std::vector<Sprite *> DemoScene::sprites()
{
    std::vector<Sprite*> sprites; //we shove all our sprites into this

    sprites.push_back(player->getSprite());
    sprites.push_back(enemy->getSprite());
    sprites.push_back(player->playerAttackSprite.get());
    sprites.push_back(healthBar.get());

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

    if(keys & KEY_START) // Reset Health
    {
        player->setHealth(100);
    }

    
    if(keys & KEY_SELECT)
    {
        //player->getSprite()->hide();
    }
    //TextStream::instance().setText("Scale: " + std::to_string(scaleX), 0, 15);


    // UI
    if(player->getHealth() <= 10)
    {
        TextStream::instance().setFontColor(CLR_RED);
    }
    else
    {
        TextStream::instance().setFontColor(CLR_WHITE);
    }
    int tileid = se_mem[background.get()->getScreenBlock()][background.get()->se_index(player->getSprite()->getX(), player->getSprite()->getY())];
    TextStream::instance().setText("Tile: " + std::to_string(tileid), 0, 0);
    // TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10); // Debug info for player direction

    //healthBar->scale(3, 1);
    
    
    //Tile 257
    if(tile_collide == 1)
    {
        TextStream::instance().setFontColor(CLR_RED);
    }
    
    // Collision Checking
    if (player->playerAttackSprite->collidesWith(*enemy->getSprite()))
    {
        enemy->getSprite()->moveTo(-100,0);
        TextStream::instance() << engine->getTimer()->getSecs();
    }
}

void DemoScene::load()
{
    //engine.get()->disableText(); //Current error with tiles overlapping Text for background 64 x 64
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(map32_palette, sizeof(map32_palette)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));

    player = std::unique_ptr<Player>(new Player(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32));
    player->getSprite()->stopAnimating();
    player->setHealth(100);
    //TextStream::instance() << player->getFaceDirection();
    // player->setMovementSpeed(10); // uncomment this for blazing fast speeds
    enemy = std::unique_ptr<Enemy>(new Enemy(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32));

    healthBar = affineBuilder.withData(healthbarTiles, sizeof(healthbarTiles))
                .withSize(SIZE_32_8)
                .withLocation(1,6)
                .buildPtr();

    background = std::unique_ptr<Background>(new Background(1, map32_tiles, sizeof(map32_tiles), map32, sizeof(map32)));
    background.get()->useMapScreenBlock(16);
    
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    engine->getTimer()->start();
}
