/*
 * Exported with nin10kit v1.7
 * Time-stamp: Sunday 02/16/2020, 20:14:44
 * 
 * Image Information
 * -----------------
 * C:\Users\ivanl\Documents\test_map.png 512@512
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef MAP_H
#define MAP_H

extern const unsigned short map_palette[4];
#define MAP_PALETTE_SIZE 8
#define MAP_PALETTE_LENGTH 4

#define MAP_PALETTE_TYPE (1 << 7)

extern const unsigned short map_tiles[96];
#define MAP_TILES 3
#define MAP_TILES_SIZE 192
#define MAP_TILES_LENGTH 96

extern const unsigned short test_map[4096];
#define TEST_MAP_MAP_WIDTH 64
#define TEST_MAP_MAP_HEIGHT 64
#define TEST_MAP_MAP_SIZE 8192
#define TEST_MAP_MAP_LENGTH 4096
#define TEST_MAP_MAP_TYPE (3 << 14)

#endif
