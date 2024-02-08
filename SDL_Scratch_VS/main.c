// main.c
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <SDL.h>

#include "atari_renderer.h"


// Constants
#define SCREEN_WIDTH (160)
#define SCREEN_HEIGHT (96)
#define WINDOW_SCALE (4)
#define WINDOW_WIDTH (SCREEN_WIDTH * WINDOW_SCALE)
#define WINDOW_HEIGHT (SCREEN_HEIGHT * WINDOW_SCALE)

// Globals
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
uint32_t* pixels;
SDL_Rect renderer_dest_rect;
bool is_running;

// Global state for rendering
uint32_t frame_index;


// Functions

bool initialize_windowing_system() {
	// Set up SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		fprintf(stderr, "SDL_Init() failed!\n");
		return false;
	}

	// Window
	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH, WINDOW_HEIGHT, 0);
	// options: SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS
	if (!window) {
		fprintf(stderr, "SDL_CreateWindow() failed!\n");
		return false;
	}

	// Renderer
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer) {
		fprintf(stderr, "SDL_CreateRenderer() failed!\n");
		return false;
	}

	// Texture
	texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, 
		SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!texture) {
		fprintf(stderr, "SDL_CreateTexture() failed!\n");
		return false;
	}

	// Allocate frame buffer
	pixels = (uint32_t*)malloc(SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(uint32_t));
	if (!pixels) {
		fprintf(stderr, "malloc() failed!\n");
		return false;
	} else {
		for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
			pixels[i] = 0x000000FF;
		}
	}

	// Set up the renderer
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, 0); // Use no interpolation
	renderer_dest_rect.x = 0;
	renderer_dest_rect.y = 0;
	renderer_dest_rect.w = WINDOW_WIDTH;
	renderer_dest_rect.h = WINDOW_HEIGHT;
	
	// Clear the window
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

	// Reset the frame index
	frame_index = 0;

	return true;
}

void clean_up_windowing_system() {
	free(pixels);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void process_keyboard_input() {
	SDL_Event event;
	SDL_PollEvent(&event);

	// Keyboard interaction
	switch (event.type) {
	case SDL_QUIT: // when 'X' button is pressed in window titlebar
		// do something
		is_running = false;
		break;
	case SDL_KEYDOWN:
		if (event.key.keysym.sym == SDLK_ESCAPE) {
			is_running = false;
		}
		break;
	}
}

void update_state() {

}

void run_render_pipeline() {
	int ti = (frame_index / 7) % 128;
	int ci = (frame_index / 30) % 7;
	for (int y = 2; y < 24; y++) {
		for (int x = 0; x < 40; x++) {
			atr_moveto(x, y);
			atr_set_tile((x + y * 13 + ti) % 128, (y) % 7 + 1);
			//set_tile(x, y, (x + y * 16) % 128, (y) % 7 + 1);
		}
	}

	atr_render(pixels, SCREEN_WIDTH, SCREEN_HEIGHT);

	// Render frame buffer
	SDL_UpdateTexture(texture, NULL, pixels, SCREEN_WIDTH * sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, &renderer_dest_rect);
	SDL_RenderPresent(renderer);

	// Update frame index
	frame_index++;
}

int main(int argc, char* argv[]) {
    printf("Started program.\n");

	if (!initialize_windowing_system()) return 0;
	if (!atari_renderer_init()) return 0;
	
	// Set up static part of display
	atr_moveto(0, 0);
	atr_print("Moves", 1);
	atr_print("123", 3);

	atr_moveto(12, 0);
	atr_print("Level", 1);
	atr_print("001", 3);

	// Game loop
	is_running = true;
	while (is_running) {
		process_keyboard_input();
		update_state();
		run_render_pipeline();

		// Wait for 1/60 second = (1000 / 60)
		SDL_Delay(1000 / 60);
	}

	atari_renderer_dispose();
    clean_up_windowing_system();

	return 0;
}

