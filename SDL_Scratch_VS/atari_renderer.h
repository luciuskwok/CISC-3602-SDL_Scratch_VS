// atari_renderer.h

bool atari_renderer_init();
void atari_renderer_dispose();
void atr_render(uint32_t* pixels, int pixel_width, int pixel_height);

void atr_moveto(int x, int y);
void atr_set_tile(int tile, int color);
int atr_get_tile();
int atr_get_tile_color();

int atr_clear(int tile, int color);
int atr_print(const char* s, int color);

