//
// Created by Wouter Groeneveld on 28/07/18.
//

#ifndef GBA_SPRITE_ENGINE_BACKGROUND_H
#define GBA_SPRITE_ENGINE_BACKGROUND_H


#include <libgba-sprite-engine/gba/tonc_types.h>

#define MAPLAYOUT_32X32 0
#define MAPLAYOUT_32X64 1
#define MAPLAYOUT_64X32 2
#define MAPLAYOUT_64X64 3

class Background {
private:
    void buildRegister();
    u32 getBgControlRegisterIndex();

protected:
    const void *data;
    const void *map;
    int size, bgIndex;
    int mapSize, mapLayout;
    int MAP_WIDTH, MAP_HEIGHT;
    int screenBlockIndex, charBlockIndex;
    

public:
    const int COLLISION_X = 1;
    const int COLLISION_Y = 2;
    const int getScreenBlock() { return screenBlockIndex; }
    const int getCharBlock() { return charBlockIndex; }
    void useMapScreenBlock(int block) { screenBlockIndex = block; }
    void scroll(int x, int y);
    void scrollSpeed(int dx, int dy);

    int se_index(int x, int y, int backx, int backy);
    int point_collision(int x, int y, int backx, int backy);
    int collision_test(int x1, int y1, int bX, int bY, int xofs, int yofs, int backx, int backy);
    //void updateCollisions(int x1, int y1, int bX, int bY, int xofs, int yofs);
    

    Background(int bgIndex, const void *data, int size, const void* map, int mapSize, int screenBlockIndex, int charBlockIndex, int mapLayout)
            : Background(bgIndex, data, size, map, mapSize) {
        this->screenBlockIndex = screenBlockIndex;
        this->charBlockIndex = charBlockIndex;
        this->mapLayout = mapLayout;

        switch(this->mapLayout)
        {
            //32*8 = 256 & 512*8 = 512
            case MAPLAYOUT_32X32:
                this->MAP_WIDTH   = 32;
                this->MAP_HEIGHT  = 32;
                break;
            case MAPLAYOUT_32X64:
                this->MAP_WIDTH   = 32;
                this->MAP_HEIGHT  = 64;
                break;
            case MAPLAYOUT_64X32:
                this->MAP_WIDTH   = 64;
                this->MAP_HEIGHT  = 32;
                break;
            case MAPLAYOUT_64X64:
                this->MAP_WIDTH   = 64;
                this->MAP_HEIGHT  = 64;
                break;
        }
    }

    Background(int bgIndex, const void *data, int size, const void* map, int mapSize) : data(data), bgIndex(bgIndex), size(size), map(map), mapLayout(MAPLAYOUT_32X32),
                                                                                        screenBlockIndex(0), charBlockIndex(bgIndex), mapSize(mapSize) {
        switch(this->mapLayout)
        {
            //32*8 = 256 & 512*8 = 512
            case MAPLAYOUT_32X32:
                this->MAP_WIDTH   = 32;
                this->MAP_HEIGHT  = 32;
                break;
            case MAPLAYOUT_32X64:
                this->MAP_WIDTH   = 32;
                this->MAP_HEIGHT  = 64;
                break;
            case MAPLAYOUT_64X32:
                this->MAP_WIDTH   = 64;
                this->MAP_HEIGHT  = 32;
                break;
            case MAPLAYOUT_64X64:
                this->MAP_WIDTH   = 64;
                this->MAP_HEIGHT  = 64;
                break;
        }
                                                                                        }
    virtual void persist();
    void updateMap(const void* map);
    void clearMap();
    void clearData();
};


#endif //GBA_SPRITE_ENGINE_BACKGROUND_H
