/*
 * Exported with nin10kit v1.7
 * Time-stamp: Monday 02/17/2020, 00:43:37
 * 
 * Image Information
 * -----------------
 * C:\Users\ivanl\Documents\map32.png 256@256
 * 
 * All bug reports / feature requests are to be filed here https://github.com/TricksterGuy/nin10kit/issues
 */

#ifndef MAP32_H
#define MAP32_H

extern const unsigned short map32_palette[4];
#define MAP32_PALETTE_SIZE 8
#define MAP32_PALETTE_LENGTH 4

#define MAP32_PALETTE_TYPE (1 << 7)

extern const unsigned short map32_tiles[96];
#define MAP32_TILES 3
#define MAP32_TILES_SIZE 192
#define MAP32_TILES_LENGTH 96

extern const unsigned short map32[1024];
#define MAP32_MAP_WIDTH 32
#define MAP32_MAP_HEIGHT 32
#define MAP32_MAP_SIZE 2048
#define MAP32_MAP_LENGTH 1024
#define MAP32_MAP_TYPE (0 << 14)

#endif

