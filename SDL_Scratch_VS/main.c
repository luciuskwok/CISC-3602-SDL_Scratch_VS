// main.c
//

#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include <stdint.h>

// Globals
SDL_Window* window;
SDL_Renderer* renderer;
SDL_Texture* texture;
uint32_t* pixels;

bool is_running;
uint32_t* color_buffer;
// int window_width = 800;
// int window_height = 600;

#define WINDOW_WIDTH (800)
#define WINDOW_HEIGHT (600)

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
		SDL_TEXTUREACCESS_STREAMING, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!texture) {
		fprintf(stderr, "SDL_CreateTexture() failed!\n");
		return false;
	}

	// Allocate frame buffer
	pixels = (uint32_t*)malloc(WINDOW_WIDTH * WINDOW_HEIGHT * sizeof(uint32_t));
	if (!pixels) {
		fprintf(stderr, "malloc() failed!\n");
		return false;
	} else {
		for (int i = 0; i < WINDOW_WIDTH * WINDOW_HEIGHT; i++) {
			pixels[i] = 0x000000FF;
		}
	}

	// Clear the window
	SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);

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

void run_render_pipeline(uint32_t* colorPalette, int* paletteIndex, int* y) {
	// Update frame buffer
	for (int x = 0; x < WINDOW_WIDTH; x++) {
		pixels[*y * WINDOW_WIDTH + x] = colorPalette[*paletteIndex];
	}
	(*y)++;
	if (*y >= WINDOW_HEIGHT) {
		*y = 0;
		(*paletteIndex)++;
		if (*paletteIndex >= 4) {
			*paletteIndex = 0;
		}
	}

	// Render frame buffer
	SDL_UpdateTexture(texture, NULL, pixels, WINDOW_WIDTH * sizeof(uint32_t));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}

int main(int argc, char* argv[]) {
    printf("Started program.\n");

	if (!initialize_windowing_system()) return 0;

	// Color palette
	uint32_t colorPalette[4] = { 0xFF0000FF, 0xFFFF00FF, 0x00FF00FF, 0x0000FFFF };
	int paletteIndex = 0;

	// Game loop
	int y = 0;
	is_running = true;
	while (is_running) {
		process_keyboard_input();
		update_state();
		run_render_pipeline(colorPalette, &paletteIndex, &y);

		// Wait for 1/60 second = (1000 / 60)
		SDL_Delay(1000 / 120);
	}

    clean_up_windowing_system();

	return 0;
}
