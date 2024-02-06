// atari_renderer.h

bool atari_renderer_init();
void atari_renderer_dispose();
void atari_renderer_render(uint32_t* pixels, int pixel_width, int pixel_height);

void set_tile(int x, int y, int tile, int color);
int get_tile(int x, int y);
int get_tile_color(int x, int y);

