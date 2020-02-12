#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "demo_scene.h"
#include "endscene.h"

#include "jscomp16.h"

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
    if(keys & KEY_SELECT) // Hold the select key for now to keep the game paused
    {
        // Pause (kinda)
        spriteManager->hideAll();
    }
    else
    {
        playerSprite = player->getSprite();

        //We will eventually need to implement a way to keep track of how many enemies are in the scene for this.
        if(spriteVector.size() != 3) //If the vector does not contain the proper amount of sprites, rebuild.
        {
            engine->updateSpritesInScene();
        }
        // Enemy
        enemy->setPlayerPos(playerSprite->getPos());
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
            enemy->getSprite()->moveTo(-100, 0);
            //TextStream::instance() << engine->getTimer()->getSecs();
        }
        if (playerSprite->collidesWith(*enemy->getSprite()))
        {
            // player->useFuel(10);
            // // Player Bounding Box
            // playerLeft = playerSprite->getX();
            // playerRight = playerSprite->getX() + playerSprite->getWidth();
            // playerTop = playerSprite->getY();
            // playerBottom = playerSprite->getY() + playerSprite->getHeight();

            // // Enemy Bounding Box
            // enemyLeft = enemy->getSprite()->getX();
            // enemyRight = enemy->getSprite()->getX() + enemy->getSprite()->getWidth();
            // enemyTop = enemy->getSprite()->getY();
            // enemyBottom = enemy->getSprite()->getY() + enemy->getSprite()->getHeight();

            // if Enemy is coming in from the player's left-side
            if (playerSprite->getCenter().x > enemy->getSprite()->getCenter().x)
            {
                player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * 2, 0);
            }
            // If Enemy is coming in from the player's right-side
            else if (playerSprite->getCenter().x < enemy->getSprite()->getCenter().x)
            {
                player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * -2, 0);
            }
            // // Uncomment this if you don't want to really prioritize left-right knockback
            // else if (playerSprite->getCenter().y > enemyBottom)
            // {
            //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 2);
            // }
            // else if (playerSprite->getCenter().y < enemyTop)
            // {
            //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -2);
            // }
            
            // I want to prioritize left-right knockback due to the screen being wider than it is tall
            else
            {
                if (playerSprite->getCenter().y > enemy->getSprite()->getCenter().y)
                {
                    player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 2);
                }
                else
                {
                    player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -2);
                }
                // player->state = new player_ns::DamagedState(10, 32, 0);
            }
        }

        // Change Scenes
        if (player->getHealth() <= 0)
        {
            engine->setScene(new EndScene(std::move(engine)));
        }
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
