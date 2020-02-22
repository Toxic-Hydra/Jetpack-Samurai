#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "map.h"
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

    

    //tile_collide = background->point_collision(player->getSprite()->getX(), player->getSprite()->getY());
    //for(int i = 0; i < 2; i++){
        tile_collide = background->collision_test(player->getSprite()->getX(), player->getSprite()->getY(),
                                                player->getSprite()->getX() + 15, player->getSprite()->getY() + 31,
                                                player->getSprite()->getDx(), player->getSprite()->getDy());

        if((tile_collide & background->COLLISION_X)) {
            player->getSprite()->setVelocity(0, player->getSprite()->getDy());
        }

        if((tile_collide & background->COLLISION_Y)) {
            player->getSprite()->setVelocity(player->getSprite()->getDx(), 0);
        }
    //}

    TextStream::instance().setText("Collision: " + std::to_string(tile_collide), 0, 0);

    if(keys & KEY_START) // Reset Health
    {
        player->setHealth(100);
    }

    
    if(keys & KEY_SELECT)
    {
        if(!player->getSprite()->isHidden())
            player->getSprite()->hide();
        else
            player->getSprite()->unhide();
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
    
    //TextStream::instance().setText("Tile: " + std::to_string(tileid), 0, 0);
    // TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10); // Debug info for player direction

    //healthBar->scale(3, 1);
    
    
    //Tile 257
    if(tile_collide >= 1)
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
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(map_palette, sizeof(map_palette)));
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

    background = std::unique_ptr<Background>(new Background(1, map_tiles, sizeof(map_tiles), test_map, sizeof(test_map), 0, 1, MAPLAYOUT_64X64));
    background.get()->useMapScreenBlock(26);
    
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    engine->getTimer()->start();
}
