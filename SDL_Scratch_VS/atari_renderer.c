// atari_renderer.c

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#include "atari_font.h"

// Constants
#define TILE_MAP_WIDTH (20)
#define TILE_MAP_HEIGHT (12)
#define COLOR_PALETTE_LEN (8)
#define TILE_FONT_LEN (128)

// Globals
uint8_t* tile_map;
int tile_map_width;
uint8_t* tile_color_map;
uint32_t* color_palette;
int cursor_x;
int cursor_y;


bool atari_renderer_init() {
	// Allocate memory
	tile_map = (uint8_t*)malloc(TILE_MAP_WIDTH * TILE_MAP_HEIGHT * sizeof(uint8_t));
	tile_color_map = (uint8_t*)malloc(TILE_MAP_WIDTH * TILE_MAP_HEIGHT * sizeof(uint8_t));
	color_palette = (uint32_t*)malloc(COLOR_PALETTE_LEN * sizeof(uint32_t));
	if (!tile_map || !tile_color_map || !color_palette) {
		fprintf(stderr, "malloc() failed!\n");
		return false;
	}

	// Set memory to defaults
	for (int i = 0; i < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; i++) tile_map[i] = 0x20;
	for (int i = 0; i < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; i++) tile_color_map[i] = 1;

	// Default colors in RGBA format
	color_palette[0] = 0x000000FF; // black
	color_palette[1] = 0xFFFFFFFF; // white
	color_palette[2] = 0xFF0000FF; // red
	color_palette[3] = 0x00FF00FF; // green
	color_palette[4] = 0x0000FFFF; // blue
	color_palette[5] = 0xFFFF00FF; // yellow
	color_palette[6] = 0x00FFFFFF; // cyan
	color_palette[7] = 0xFF00FFFF; // magenta

	return true;
}

void atari_renderer_dispose() {
	free(tile_map);
	tile_map = NULL;
	free(tile_color_map);
	tile_color_map = NULL;
	free(color_palette);
	color_palette = NULL;
}

void atr_set_pixel_to_color(uint32_t* pixels, int pixel_width, int pixel_height, int x, int y, uint32_t color) {
	if (x < 0 || x >= pixel_width) return;
	if (y < 0 || y >= pixel_height) return;
	pixels[y * pixel_width + x] = color;
}

void atr_render(uint32_t* pixels, int pixel_width, int pixel_height) {
	for (int ty = 0; ty < TILE_MAP_HEIGHT; ty++) {
		for (int tx = 0; tx < TILE_MAP_WIDTH; tx++) {
			// Get tile index and color info for tile
			int index = ty * TILE_MAP_WIDTH + tx;
			int tile = tile_map[index];
			int fg_color = color_palette[tile_color_map[index] % COLOR_PALETTE_LEN];
			int bg_color = color_palette[0];
			int color;

			// Draw the tile
			for (int cy = 0; cy < 8; cy++) {
				int a = atari_font[(tile * 8 + cy) % atari_font_len];
				for (int cx = 7; cx >= 0; cx--) {
					color = (a & 0x01) ? fg_color : bg_color;
					atr_set_pixel_to_color(pixels, pixel_width, pixel_height, tx * 8 + cx, ty * 8 + cy, color);
					a = a >> 1;
				}
			}
		}
	}
}

void atr_moveto(int x, int y) {
	cursor_x = x;
	cursor_y = y;
}

bool atr_is_cursor_on_screen() {
	if (cursor_x < 0 || cursor_x >= TILE_MAP_WIDTH) return false;
	if (cursor_y < 0 || cursor_y >= TILE_MAP_HEIGHT) return false;
	return true;
}

void atr_set_tile(int tile, int color) {
	if (atr_is_cursor_on_screen()) {
		int index = cursor_x + cursor_y * TILE_MAP_WIDTH;
		tile_map[index] = tile % TILE_FONT_LEN;
		tile_color_map[index] = color % COLOR_PALETTE_LEN;
	}
}

int atr_get_tile() {
	if (!atr_is_cursor_on_screen()) return -1;
	int index = cursor_x + cursor_y * TILE_MAP_WIDTH;
	return tile_map[index];
}

int atr_get_tile_color() {
	if (!atr_is_cursor_on_screen()) return -1;
	int index = cursor_x + cursor_y * TILE_MAP_WIDTH;
	return tile_color_map[index];
}

int atr_clear(int tile, int color) {
	for (int i = 0; i < TILE_MAP_WIDTH * TILE_MAP_HEIGHT; i++) {
		tile_map[i] = tile;
		tile_color_map[i] = color;
	}
}

int atr_print(const char* s, int color) {
	int i = 0;
	while (s[i] != 0 && cursor_x < TILE_MAP_WIDTH) {
		atr_set_tile(s[i], color);
		cursor_x++;
		i++;
	}
}

