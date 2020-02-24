#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "demo_scene.h"
#include "endscene.h"

#include "jscomp16.h"

// static int bufferFrames = 0;

DemoScene::DemoScene(const std::shared_ptr<GBAEngine> &engine) : Scene(engine) {}

std::vector<Background *> DemoScene::backgrounds()
{
    return {};
}

std::vector<Sprite *> DemoScene::sprites()
{
    spriteVector.clear(); //we shove all our sprites into this

    // spriteVector.push_back(player->getSprite());
    // spriteVector.push_back(enemy->getSprite());
    // spriteVector.push_back(player->playerAttackSprite.get());

    return spriteVector;
}

void DemoScene::tick(u16 keys)
{
    // if(keys & KEY_SELECT) // Hold the select key for now to keep the game paused
    // {
    //     // Pause (kinda)
    //     spriteManager->hideAll();
    // }
    // else
    // {
    //     playerSprite = player->getSprite();

    //     //We will eventually need to implement a way to keep track of how many enemies are in the scene for this.
    //     if(spriteVector.size() != 3) //If the vector does not contain the proper amount of sprites, rebuild.
    //     {
    //         engine->updateSpritesInScene();
    //     }
    //     // Enemy
    //     enemy->setPlayerPos(playerSprite->getPos());
    //     enemy->tick();


    //     // Player

    //     // Not sure how to do this, but I wish to implement some sort of input leniency
    //     // in case players cannot tap a button for exactly one frame. This was my best
    //     // attempt.
    //     // - Charles
    //     if(bufferFrames % 5 == 0)
    //     {
    //         player->readInput(keys); // Read input every 5 frames
    //     }
    //     bufferFrames++;
    //     player->tick();

    //     if(keys & KEY_START) // Reset Health
    //     {
    //         player->setHealth(100);
    //     }


    //     // UI
    //     if(player->getHealth() <= 10)
    //     {
    //         TextStream::instance().setFontColor(CLR_RED);
    //     }
    //     else
    //     {
    //         TextStream::instance().setFontColor(CLR_WHITE);
    //     }
    //     TextStream::instance().setText("Fuel: " + std::to_string(player->getHealth()), 0, 0);
    //     // TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10); // Debug info for player direction


    //     // Collision Checking
    //     if (player->playerAttackSprite->collidesWith(*enemy->getSprite()))
    //     {
    //         enemy->getSprite()->moveTo(-100, 0);
    //         //TextStream::instance() << engine->getTimer()->getSecs();
    //     }
    //     if (playerSprite->collidesWith(*enemy->getSprite()))
    //     {
    //         if (player->state->stateID != 5)
    //         {
    //             // player->useFuel(10);
    //             // // Player Bounding Box
    //             // playerLeft = playerSprite->getX();
    //             // playerRight = playerSprite->getX() + playerSprite->getWidth();
    //             // playerTop = playerSprite->getY();
    //             // playerBottom = playerSprite->getY() + playerSprite->getHeight();

    //             // // Enemy Bounding Box
    //             // enemyLeft = enemy->getSprite()->getX();
    //             // enemyRight = enemy->getSprite()->getX() + enemy->getSprite()->getWidth();
    //             // enemyTop = enemy->getSprite()->getY();
    //             // enemyBottom = enemy->getSprite()->getY() + enemy->getSprite()->getHeight();

    //             // if Enemy is coming in from the player's left-side
    //             if (playerSprite->getCenter().x > enemy->getSprite()->getCenter().x)
    //             {
    //                 player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * 2, 0);
    //             }
    //             // If Enemy is coming in from the player's right-side
    //             else if (playerSprite->getCenter().x < enemy->getSprite()->getCenter().x)
    //             {
    //                 player->state = new player_ns::DamagedState(10, playerSprite->getWidth() * -2, 0);
    //             }
    //             // // Uncomment this if you don't want to really prioritize left-right knockback
    //             // else if (playerSprite->getCenter().y > enemyBottom)
    //             // {
    //             //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 2);
    //             // }
    //             // else if (playerSprite->getCenter().y < enemyTop)
    //             // {
    //             //     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -2);
    //             // }
                
    //             // I want to prioritize left-right knockback due to the screen being wider than it is tall
    //             else
    //             {
    //                 if (playerSprite->getCenter().y > enemy->getSprite()->getCenter().y)
    //                 {
    //                     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * 3);
    //                 }
    //                 else
    //                 {
    //                     player->state = new player_ns::DamagedState(10, 0, playerSprite->getHeight() * -3);
    //                 }
    //                 // player->state = new player_ns::DamagedState(10, 32, 0);
    //             }
    //         }
    //         else
    //         {
    //             player->useFuel(5);
    //             enemy->getSprite()->moveTo(enemy->getSprite()->getX() - 2 * enemy->getSprite()->getWidth() * enemy->getSprite()->getDx(),
    //                                        enemy->getSprite()->getY() - 2 * enemy->getSprite()->getHeight() * enemy->getSprite()->getDy());
    //         }
    //     }

        // // Change Scenes
        // if (player->getHealth() <= 0)
        // {
        //     engine->setScene(new EndScene(std::move(engine)));
        // }
    // }

    /////////////////////////
    //
    // Bounding Box Test
    //
    /////////////////////////
    // Change text color
    // if (innerPlayerBox->getDx < innerEnemyBox->right &&
    //     innerPlayerBox->right > innerEnemyBox->getDx &&
    //     innerPlayerBox->top < innerEnemyBox->bottom &&
    //     innerPlayerBox->bottom > innerEnemyBox->top)
    if (innerPlayerBox->collidesWith(*innerEnemyBox))
    {
        TextStream::instance().setFontColor(CLR_RED);
        // delete innerPlayerBox;
        // delete innerEnemyBox;
        innerPlayerBox.reset();
        innerEnemyBox.reset();
    }
    // else if(playerBox->getDx < enemyBox->right &&
    //         playerBox->right > enemyBox->getDx &&
    //         playerBox->top < enemyBox->bottom &&
    //         playerBox->bottom > enemyBox->top)
    else if (playerBox->collidesWith(*enemyBox))
    {
        TextStream::instance().setFontColor(CLR_ORANGE);
    }
    else
    {
        TextStream::instance().setFontColor(CLR_WHITE);
    }
    // Print Coordinates
    TextStream::instance().setText("(" + std::to_string(playerBox->getX()) + ", " + std::to_string(playerBox->getY()) + ")", 0, 0);
    TextStream::instance().setText("(" + std::to_string(innerPlayerBox->getX()) + ", " + std::to_string(innerPlayerBox->getY()) + ")", 1, 0);
    TextStream::instance().setText("(" + std::to_string(enemyBox->getX()) + ", " + std::to_string(enemyBox->getY()) + ")", 18, 18);
    TextStream::instance().setText("(" + std::to_string(innerEnemyBox->getX()) + ", " + std::to_string(innerEnemyBox->getY()) + ")", 19, 18);

    // Move Player Box
    if((keys & KEY_LEFT) && (keys & KEY_RIGHT))
    {
        // Do nothing
    }
    else if (keys & KEY_LEFT)
    {
        // rc_move(playerBox, -1, 0);
        // rc_move(innerPlayerBox, -1, 0);
        playerBox->move(-1, 0);
        innerPlayerBox->move(-1, 0);
    }
    else if (keys & KEY_RIGHT)
    {
        // rc_move(playerBox, 1, 0);
        // rc_move(innerPlayerBox, 1, 0);
        playerBox->move(1, 0);
        innerPlayerBox->move(1, 0);
    }

    if((keys & KEY_UP) && (keys & KEY_DOWN))
    {
        // Do Nothing
    }
    else if (keys & KEY_UP)
    {
        // rc_move(playerBox, 0, -1);
        // rc_move(innerPlayerBox, 0, -1);
        playerBox->move(0, -1);
        innerPlayerBox->move(0, -1);
    }
    else if (keys & KEY_DOWN)
    {
        // rc_move(playerBox, 0, 1);
        // rc_move(innerPlayerBox, 0, 1);
        playerBox->move(0, 1);
        innerPlayerBox->move(0, 1);
    }

    if (keys & KEY_SELECT)
    {
        // delete playerBox;
        // delete enemyBox;
        // delete innerPlayerBox;
        // delete innerEnemyBox;
        engine->setScene(new EndScene(engine));
    }
}

void DemoScene::load()
{
    
    foregroundPalette = std::unique_ptr<ForegroundPaletteManager>(new ForegroundPaletteManager(sharedPal, sizeof(sharedPal)));
    TextStream::instance().clear();

    // player = std::unique_ptr<Player>(new Player(GBA_SCREEN_WIDTH/2 -32, GBA_SCREEN_HEIGHT/2 -32));
    // player->getSprite()->stopAnimating();
    // player->setHealth(100);
    // //TextStream::instance() << player->getFaceDirection();
    // // player->setMovementSpeed(10); // uncomment this for blazing fast speeds
    // enemy = std::unique_ptr<Enemy>(new Enemy(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32));

    /////////////////////////
    //
    // Bounding Box Test
    //
    /////////////////////////
    playerBox = std::make_unique<CollisionBox>(10, 10, 50, 50);
    innerPlayerBox = std::make_unique<CollisionBox>(playerBox->getX() + 10, playerBox->getY() + 10, 30, 30);
    enemyBox = std::make_unique<CollisionBox>(GBA_SCREEN_WIDTH - 60, GBA_SCREEN_HEIGHT - 60, 50, 50);
    innerEnemyBox = std::make_unique<CollisionBox>(enemyBox->getX() + 10, enemyBox->getY() + 10, 30, 30);
    // rc_set2(playerBox, 10, 10, 50, 50);
    // rc_set2(innerPlayerBox, playerBox->left + 10, playerBox->top + 10, 30, 30);
    // rc_set2(enemyBox, GBA_SCREEN_WIDTH - 60, GBA_SCREEN_HEIGHT - 60, 50, 50);
    // rc_set2(innerEnemyBox, enemyBox->left + 10, enemyBox->top + 10, 30, 30);
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    engine->getTimer()->start();

    
}
