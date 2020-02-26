#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "map.h"
#include "demo_scene.h"
#include "endscene.h"

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
        // spriteManager->hideAll();
        engine->setScene(new EndScene(engine));
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

        tile_collide = background->collision_test(player->getSprite()->getX(), player->getSprite()->getY(),
                                                player->getSprite()->getX() + 15, player->getSprite()->getY() + 31,
                                                player->getSprite()->getDx(), player->getSprite()->getDy());

        if((tile_collide & background->COLLISION_X)) {
            player->getSprite()->setVelocity(0, player->getSprite()->getDy());
        }

        if((tile_collide & background->COLLISION_Y)) {
            player->getSprite()->setVelocity(player->getSprite()->getDx(), 0);
        }


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

        TextStream::instance().setText("(" + std::to_string(enemy->innerBox->getX()) + ", " + std::to_string(enemy->innerBox->getY()) + ")", 14, 18);

        // Collision Checking
        // Enemy Inner Box vs. Player Attack
        if (enemy->innerBox->collidesWith(*player->playerAttackSprite))
        {
            enemy->getSprite()->moveTo(-100, 0);
        }
        // Enemy vs. Player Attack
        else if (player->playerAttackSprite->collidesWith(*enemy->getSprite()))
        {
            if (enemy->getSprite()->getCenter().x > playerSprite->getCenter().x)
            {
                enemy->getSprite()->moveTo(enemy->getSprite()->getX() + 32, enemy->getSprite()->getY());
            }
            else if (enemy->getSprite()->getCenter().x < playerSprite->getCenter().x)
            {
                enemy->getSprite()->moveTo(enemy->getSprite()->getX() - 32, enemy->getSprite()->getY());
            }
            else
            {
                if (enemy->getSprite()->getCenter().y > playerSprite->getCenter().y)
                {
                    enemy->getSprite()->moveTo(enemy->getSprite()->getX(), enemy->getSprite()->getY() + enemy->getSprite()->getHeight());
                }
                else
                {
                    enemy->getSprite()->moveTo(enemy->getSprite()->getX(), enemy->getSprite()->getY() - enemy->getSprite()->getHeight());
                }
            }
            //TextStream::instance() << engine->getTimer()->getSecs();
        }
        // Player vs. Enemy
        if (playerSprite->collidesWith(*enemy->getSprite()))
        {
            // if (player->state->stateID != 5)
            // {
            //     // player->useFuel(10);
            //     // // Player Bounding Box
            //     // playerLeft = playerSprite->getX();
            //     // playerRight = playerSprite->getX() + playerSprite->getWidth();
            //     // playerTop = playerSprite->getY();
            //     // playerBottom = playerSprite->getY() + playerSprite->getHeight();

            //     // // Enemy Bounding Box
            //     // enemyLeft = enemy->getSprite()->getX();
            //     // enemyRight = enemy->getSprite()->getX() + enemy->getSprite()->getWidth();
            //     // enemyTop = enemy->getSprite()->getY();
            //     // enemyBottom = enemy->getSprite()->getY() + enemy->getSprite()->getHeight();

            //     // if Enemy is coming in from the player's left-side
            //     if (playerSprite->getCenter().x > enemy->getSprite()->getCenter().x)
            //     {
            //         player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * 2, 0);
            //     }
            //     // If Enemy is coming in from the player's right-side
            //     else if (playerSprite->getCenter().x < enemy->getSprite()->getCenter().x)
            //     {
            //         player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * -2, 0);
            //     }
            //     // // Uncomment this if you don't want to really prioritize left-right knockback
            //     // else if (playerSprite->getCenter().y > enemyBottom)
            //     // {
            //     //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 2);
            //     // }
            //     // else if (playerSprite->getCenter().y < enemyTop)
            //     // {
            //     //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -2);
            //     // }
                
            //     // I want to prioritize left-right knockback due to the screen being wider than it is tall
            //     else
            //     {
            //         if (playerSprite->getCenter().y > enemy->getSprite()->getCenter().y)
            //         {
            //             player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 3);
            //         }
            //         else
            //         {
            //             player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -3);
            //         }
            //         // player->state = new player_ns::DamagedState(10, 32, 0);
            //     }
            // }
            // else
            // {
            //     player->useFuel(5);
            //     enemy->getSprite()->moveTo(enemy->getSprite()->getX() - 2 * enemy->getSprite()->getWidth() * enemy->getSprite()->getDx(),
            //                                enemy->getSprite()->getY() - 2 * enemy->getSprite()->getHeight() * enemy->getSprite()->getDy());
            // }

            //Enemy collision
            if (enemy->getSprite()->getDx() > 0 || enemy->getSprite()->getDx() < 0)
            {
                enemy->getSprite()->setVelocity(0, enemy->getSprite()->getDy());
            }

            if (enemy->getSprite()->getDy() > 0 || enemy->getSprite()->getDy() < 0)
            {
                enemy->getSprite()->setVelocity(enemy->getSprite()->getDx(), 0);
            }
            //PLAYER collisions
            if ( player->getSprite()->getX() < enemy->getSprite()->getX())
            {

                if ( player->getKey() & KEY_LEFT)
                {
                    player->getSprite()->setVelocity(-player->getMovementSpeed(), player->getSprite()->getDy());
                }
                else
                    player->getSprite()->setVelocity(0, player->getSprite()->getDy());
                
            }
            else if (player->getSprite()->getX() > enemy->getSprite()->getX())
            {
                if ( player->getKey() & KEY_RIGHT)
                {
                    player->getSprite()->setVelocity(player->getMovementSpeed(), player->getSprite()->getDy());
                }
                else
                    player->getSprite()->setVelocity(0, player->getSprite()->getDy());
            }
            //Y
            if ( player->getSprite()->getY() < enemy->getSprite()->getY())
            {

                if ( player->getKey() & KEY_UP)
                {
                    player->getSprite()->setVelocity(player->getSprite()->getDx(),-player->getMovementSpeed());
                }
                else
                    player->getSprite()->setVelocity(player->getSprite()->getDx() , 0);
                
            }
            else if (player->getSprite()->getY() > enemy->getSprite()->getY())
            {
                if ( player->getKey() & KEY_DOWN)
                {
                    player->getSprite()->setVelocity(player->getSprite()->getDx(), player->getMovementSpeed());
                }
                else
                    player->getSprite()->setVelocity(player->getSprite()->getDx() , 0);
            }
        }
        // if(player->getSprite()->collidesWith(*enemy->getSprite()))
        // {
            // //Enemy collision
            // if (enemy->getSprite()->getDx() > 0 || enemy->getSprite()->getDx() < 0)
            // {
            //     enemy->getSprite()->setVelocity(0, enemy->getSprite()->getDy());
            // }

            // if (enemy->getSprite()->getDy() > 0 || enemy->getSprite()->getDy() < 0)
            // {
            //     enemy->getSprite()->setVelocity(enemy->getSprite()->getDx(), 0);
            // }
            // //PLAYER collisions
            // if ( player->getSprite()->getX() < enemy->getSprite()->getX())
            // {

            //     if ( player->getKey() & KEY_LEFT)
            //     {
            //         player->getSprite()->setVelocity(-player->getMovementSpeed(), player->getSprite()->getDy());
            //     }
            //     else
            //         player->getSprite()->setVelocity(0, player->getSprite()->getDy());
                
            // }
            // else if (player->getSprite()->getX() > enemy->getSprite()->getX())
            // {
            //     if ( player->getKey() & KEY_RIGHT)
            //     {
            //         player->getSprite()->setVelocity(player->getMovementSpeed(), player->getSprite()->getDy());
            //     }
            //     else
            //         player->getSprite()->setVelocity(0, player->getSprite()->getDy());
            // }
            // //Y
            // if ( player->getSprite()->getY() < enemy->getSprite()->getY())
            // {

            //     if ( player->getKey() & KEY_UP)
            //     {
            //         player->getSprite()->setVelocity(player->getSprite()->getDx(),-player->getMovementSpeed());
            //     }
            //     else
            //         player->getSprite()->setVelocity(player->getSprite()->getDx() , 0);
                
            // }
            // else if (player->getSprite()->getY() > enemy->getSprite()->getY())
            // {
            //     if ( player->getKey() & KEY_DOWN)
            //     {
            //         player->getSprite()->setVelocity(player->getSprite()->getDx(), player->getMovementSpeed());
            //     }
            //     else
            //         player->getSprite()->setVelocity(player->getSprite()->getDx() , 0);
            // }
        // }

        // Change Scenes
        if (player->getHealth() <= 0)
        {
            engine->setScene(new EndScene(std::move(engine)));
        }
    }
}

void DemoScene::load()
{
    backgroundPalette = std::unique_ptr<BackgroundPaletteManager>(new BackgroundPaletteManager(map_palette, sizeof(map_palette)));
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    TextStream::instance().clear();

    player = std::make_unique<Player>(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32);
    player->getSprite()->stopAnimating();
    player->setHealth(100);
    //TextStream::instance() << player->getFaceDirection();
    // player->setMovementSpeed(10); // uncomment this for blazing fast speeds
    enemy = std::make_unique<Enemy>(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32);

    background = std::make_unique<Background>(1, map_tiles, sizeof(map_tiles), test_map, sizeof(test_map), 0, 1, MAPLAYOUT_64X64);
    background.get()->useMapScreenBlock(26);
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    engine->getTimer()->start();

    
}
