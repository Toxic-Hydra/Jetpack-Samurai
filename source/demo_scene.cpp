#include <libgba-sprite-engine/sprites/sprite_builder.h>
#include <libgba-sprite-engine/gba_engine.h>
#include <libgba-sprite-engine/background/text_stream.h>
#include <libgba-sprite-engine/gbavector.h>
#include <tonc_video.h>
#include <algorithm>
#include <sstream>
#include "map.h"
#include "demo_scene.h"
#include "endscene.h"
#include "BoyScout.h"
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
    spriteVector.push_back(enemy->swordAttackSprite.get());
    spriteVector.push_back(player->playerAttackSprite.get());
    spriteVector.push_back(player->attackBottom.get());

    return spriteVector;
}

void DemoScene::tick(u16 keys)
{
    //BoyScoutUpdateSong(); //Don't forget to free memory upon leaving this state.
    if(keys & KEY_SELECT) // Hold the select key for now to keep the game paused
    {
        // Pause (kinda)
        // spriteManager->hideAll();
        engine->setScene(new EndScene(engine));
    }
    else
    {
        

        //We will eventually need to implement a way to keep track of how many enemies are in the scene for this.
        if(spriteVector.size() != 5) //If the vector does not contain the proper amount of sprites, rebuild.
        {
            engine->updateSpritesInScene();
        }
      
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
        playerSprite = player->getSprite();

        
        //COLLISIONS: TILE
        tile_collide = background->collision_test(playerSprite->getX(), playerSprite->getY(),
                                                playerSprite->getX() + 15, playerSprite->getY() + 31,
                                                playerSprite->getDx(), playerSprite->getDy(), scrollx, scrolly);

        if((tile_collide & background->COLLISION_X)) {
            playerSprite->setVelocity(0, playerSprite->getDy());
            
        }

        if((tile_collide & background->COLLISION_Y)) {
            playerSprite->setVelocity(playerSprite->getDx(), 0);
        }

        //CAMERA
        //TODO:
        //High possibility most of this should be in player class, refactor.
        //could be functions that take in player, enemies, current screenx and return a new screenx.
        //Also needs to account for the possibility of multiple enemies
        //Doesn't account for dashing.
        //X AXIS CAMERA MOVEMENT
        
        if ( !(tile_collide & background->COLLISION_X) && keys & KEY_LEFT && scrollx > 0) {
            if ((int)playerSprite->getX() <= border) //left end of screen
            {
                if(player->state->stateID == 3) { //Player can dash past the camera bounds
                    //check for can dash
                    scrollx += player->getDashSpeed();
                }
                //lock player, just move screen
                scrollx -= player->getMovementSpeed();
                if ((int)playerSprite->getX() < border)
                    playerSprite->moveTo(border, playerSprite->getY());
                playerSprite->setVelocity(0, playerSprite->getDy());
                //Account for all enemies
                if(!enemy->getSprite()->isOffScreen())
                    enemy->getSprite()->setVelocity(0, enemy->getSprite()->getDy());
                //if(typeid(enemy->state)==typeid(IdleStateShield))
                
                
                
            }
        }       
        else if( !(tile_collide & background->COLLISION_X) && keys & KEY_RIGHT && scrollx < 272) { //272 is map_width - screen_width

            if ((int)playerSprite->getX() >= (GBA_SCREEN_WIDTH - 16 - border)) // right end of screen.
            {

                if ((int)playerSprite->getX() > (GBA_SCREEN_WIDTH - 16 - border))
                    playerSprite->moveTo((GBA_SCREEN_WIDTH - 16 - border), playerSprite->getY());
                //lock player right, move screen
                scrollx += player->getMovementSpeed();
                playerSprite->setVelocity(0, playerSprite->getDy());
                //Account for all enemies
                if(!enemy->getSprite()->isOffScreen())
                    enemy->getSprite()->setVelocity(0, enemy->getSprite()->getDy());
                
            }
        }
        //Y AXIS CAMERA MOVEMENT
        if ( !(tile_collide & background->COLLISION_Y) && keys & KEY_UP && scrolly > 0) {
            if ((int)playerSprite->getY() <= border) //left end of screen
            {
                if ((int)playerSprite->getY() < border)
                    playerSprite->moveTo(playerSprite->getX(), border);
                //lock player, just move screen
                scrolly -= player->getMovementSpeed();
                playerSprite->setVelocity(playerSprite->getDx() , 0);
                //Account for all enemies
                if(!enemy->getSprite()->isOffScreen())
                    enemy->getSprite()->setVelocity(enemy->getSprite()->getDx() , 0);
            }
        }
        else if( !(tile_collide & background->COLLISION_Y) && keys & KEY_DOWN && scrolly < 352) { //map_height - screen_height = 352

            if ((int)playerSprite->getY() >= (GBA_SCREEN_HEIGHT - 32 - border)) // right end of screen. accounting for player vertical size
            {
                if ((int)playerSprite->getY() > (GBA_SCREEN_HEIGHT - 32 - border))
                    playerSprite->moveTo(playerSprite->getX(), (GBA_SCREEN_HEIGHT - 32 - border));
                //lock player right, move screen
                scrolly += player->getMovementSpeed();
                playerSprite->setVelocity( playerSprite->getDx(), 0);
                //Account for all enemies
                if(!enemy->getSprite()->isOffScreen())
                    enemy->getSprite()->setVelocity( enemy->getSprite()->getDx() , 0);
            }
        }
        //End Camera block.

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
            //TextStream::instance().setFontColor(CLR_WHITE);
        }
        TextStream::instance().setText("Fuel: " + std::to_string(player->getHealth()), 11, 0);
        // TextStream::instance().setText(std::to_string(player->getFaceDirection()), 5, 10); // Debug info for player direction

        //TextStream::instance().setText("(" + std::to_string(enemy->innerBox->getX()) + ", " + std::to_string(enemy->innerBox->getY()) + ")", 14, 18);

        // Collision Checking
        // SwordEnemy Inner Box vs. Player Attack
        if (((player->faceDirection == 0 && enemy->faceDirection == 0) || (player->faceDirection == 1 && enemy->faceDirection == 1)) &&
              (enemy->innerBox->collidesWith(*player->playerAttackSprite) || enemy->innerBox->collidesWith(*player->attackBottom)))
        {
            enemy->getSprite()->moveTo(-100, 0);
        }
        // SwordEnemy vs. Player Attack
        else if (player->playerAttackSprite->collidesWith(*enemy->getSprite()) || player->attackBottom->collidesWith(*enemy->getSprite()))
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
        // Player vs. SwordEnemy
        if (playerSprite->collidesWith(*enemy->getSprite()))
        {
            //Enemy collision
            if (enemy->getSprite()->getDx() > 0 || enemy->getSprite()->getDx() < 0)
            {
                enemy->getSprite()->setVelocity(0, enemy->getSprite()->getDy());
            }

            if (enemy->getSprite()->getDy() > 0 || enemy->getSprite()->getDy() < 0)
            {
                enemy->getSprite()->setVelocity(enemy->getSprite()->getDx(), 0);
            }

            if (enemy->state->stateID == 2 || enemy->swordAttackSprite->collidesWith(*player->getSprite()))
            {
                player->useFuel(1);
            }

            //PLAYER collisions
            if ( playerSprite->getX() < enemy->getSprite()->getX())
            {

                if ( !(tile_collide & background->COLLISION_X) && player->getKey() & KEY_LEFT)
                {
                    playerSprite->setVelocity(-player->getMovementSpeed(), playerSprite->getDy());
                }
                else
                    playerSprite->setVelocity(0, playerSprite->getDy());
                
            }
            else if (playerSprite->getX() > enemy->getSprite()->getX())
            {
                if ( !(tile_collide & background->COLLISION_X) && player->getKey() & KEY_RIGHT)
                {
                    playerSprite->setVelocity(player->getMovementSpeed(), playerSprite->getDy());
                }
                else
                    playerSprite->setVelocity(0, playerSprite->getDy());
            }
            //Y
            if ( playerSprite->getY() < enemy->getSprite()->getY())
            {

                if ( !(tile_collide & background->COLLISION_Y) && player->getKey() & KEY_UP)
                {
                    playerSprite->setVelocity(playerSprite->getDx(),-player->getMovementSpeed());
                }
                else
                    playerSprite->setVelocity(playerSprite->getDx() , 0);
                
            }
            else if (playerSprite->getY() > enemy->getSprite()->getY())
            {
                if ( !(tile_collide & background->COLLISION_Y) && player->getKey() & KEY_DOWN)
                {
                    playerSprite->setVelocity(playerSprite->getDx(), player->getMovementSpeed());
                }
                else
                    playerSprite->setVelocity(playerSprite->getDx() , 0);
            }
        }


        // Change Scenes
        if (player->getHealth() <= 0)
        {
            free((void *)BoyScoutGetMemoryArea());
            engine->setScene(new EndScene(std::move(engine)));
        }

        background->scroll(scrollx, scrolly);

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
    enemy = std::make_unique<EnemySword>(GBA_SCREEN_WIDTH/2 + 32, GBA_SCREEN_HEIGHT/2 +32);


    //Village bg requires text to be disabled, its simply too big.
    background = std::make_unique<Background>(1, map_tiles, sizeof(map_tiles), test_map, sizeof(test_map), 0, 1, MAPLAYOUT_64X64);
    background.get()->useMapScreenBlock(26);
    
    engine->enqueueMusic(jscomp16, jscomp16_bytes);
    /*
    BoyScoutInitialize();
    nBSSongSize = BoyScoutGetNeededSongMemory((unsigned char*)Aegis_bgf);
    BoyScoutSetMemoryArea((unsigned int)malloc(nBSSongSize));
    BoyScoutOpenSong((unsigned char*)Aegis_bgf);
    BoyScoutPlaySong(0);
    */
    engine->getTimer()->start();

    
}
