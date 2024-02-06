// This font was made by taking the Atari ROM character set data, and then 
// reorganizing the tiles so they match the ASCII table.

unsigned char atari_font[] = {
  0x00, 0x36, 0x7f, 0x7f,
  0x3e, 0x1c, 0x08, 0x00, 0x18, 0x18, 0x18, 0x1f, 0x1f, 0x18, 0x18, 0x18,
  0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x18, 0x18, 0x18, 0xf8,
  0xf8, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xf8, 0xf8, 0x18, 0x18, 0x18,
  0x00, 0x00, 0x00, 0xf8, 0xf8, 0x18, 0x18, 0x18, 0x03, 0x07, 0x0e, 0x1c,
  0x38, 0x70, 0xe0, 0xc0, 0xc0, 0xe0, 0x70, 0x38, 0x1c, 0x0e, 0x07, 0x03,
  0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0x00, 0x00, 0x00, 0x00,
  0x0f, 0x0f, 0x0f, 0x0f, 0x80, 0xc0, 0xe0, 0xf0, 0xf8, 0xfc, 0xfe, 0xff,
  0x0f, 0x0f, 0x0f, 0x0f, 0x00, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0,
  0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
  0xf0, 0xf0, 0xf0, 0xf0, 0x00, 0x1c, 0x1c, 0x77, 0x77, 0x08, 0x1c, 0x00,
  0x00, 0x00, 0x00, 0x1f, 0x1f, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0xff,
  0xff, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18, 0xff, 0xff, 0x18, 0x18, 0x18,
  0x00, 0x00, 0x3c, 0x7e, 0x7e, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x00,
  0xff, 0xff, 0xff, 0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
  0x00, 0x00, 0x00, 0xff, 0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0xff,
  0xff, 0x00, 0x00, 0x00, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
  0x18, 0x18, 0x18, 0x1f, 0x1f, 0x00, 0x00, 0x00, 0x78, 0x60, 0x78, 0x60,
  0x7e, 0x18, 0x1e, 0x00, 0x00, 0x18, 0x3c, 0x7e, 0x18, 0x18, 0x18, 0x00,
  0x00, 0x18, 0x18, 0x18, 0x7e, 0x3c, 0x18, 0x00, 0x00, 0x18, 0x30, 0x7e,
  0x30, 0x18, 0x00, 0x00, 0x00, 0x18, 0x0c, 0x7e, 0x0c, 0x18, 0x00, 0x00,

  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x18,
  0x18, 0x00, 0x18, 0x00, 0x00, 0x66, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x66, 0xff, 0x66, 0x66, 0xff, 0x66, 0x00, 0x18, 0x3e, 0x60, 0x3c,
  0x06, 0x7c, 0x18, 0x00, 0x00, 0x66, 0x6c, 0x18, 0x30, 0x66, 0x46, 0x00,
  0x1c, 0x36, 0x1c, 0x38, 0x6f, 0x66, 0x3b, 0x00, 0x00, 0x18, 0x18, 0x18,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1c, 0x18, 0x18, 0x1c, 0x0e, 0x00,
  0x00, 0x70, 0x38, 0x18, 0x18, 0x38, 0x70, 0x00, 0x00, 0x66, 0x3c, 0xff,
  0x3c, 0x66, 0x00, 0x00, 0x00, 0x18, 0x18, 0x7e, 0x18, 0x18, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x30, 0x00, 0x00, 0x00, 0x7e,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x06, 0x0c, 0x18, 0x30, 0x60, 0x40, 0x00, 0x00, 0x3c, 0x66, 0x6e,
  0x76, 0x66, 0x3c, 0x00, 0x00, 0x18, 0x38, 0x18, 0x18, 0x18, 0x7e, 0x00,
  0x00, 0x3c, 0x66, 0x0c, 0x18, 0x30, 0x7e, 0x00, 0x00, 0x7e, 0x0c, 0x18,
  0x0c, 0x66, 0x3c, 0x00, 0x00, 0x0c, 0x1c, 0x3c, 0x6c, 0x7e, 0x0c, 0x00,
  0x00, 0x7e, 0x60, 0x7c, 0x06, 0x66, 0x3c, 0x00, 0x00, 0x3c, 0x60, 0x7c,
  0x66, 0x66, 0x3c, 0x00, 0x00, 0x7e, 0x06, 0x0c, 0x18, 0x30, 0x30, 0x00,
  0x00, 0x3c, 0x66, 0x3c, 0x66, 0x66, 0x3c, 0x00, 0x00, 0x3c, 0x66, 0x3e,
  0x06, 0x0c, 0x38, 0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x00,
  0x00, 0x00, 0x18, 0x18, 0x00, 0x18, 0x18, 0x30, 0x06, 0x0c, 0x18, 0x30,
  0x18, 0x0c, 0x06, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x7e, 0x00, 0x00,
  0x60, 0x30, 0x18, 0x0c, 0x18, 0x30, 0x60, 0x00, 0x00, 0x3c, 0x66, 0x0c,
  0x18, 0x00, 0x18, 0x00, 
  
  0x00, 0x3c, 0x66, 0x6e, 0x6e, 0x60, 0x3e, 0x00,
  0x00, 0x18, 0x3c, 0x66, 0x66, 0x7e, 0x66, 0x00, 0x00, 0x7c, 0x66, 0x7c,
  0x66, 0x66, 0x7c, 0x00, 0x00, 0x3c, 0x66, 0x60, 0x60, 0x66, 0x3c, 0x00,
  0x00, 0x78, 0x6c, 0x66, 0x66, 0x6c, 0x78, 0x00, 0x00, 0x7e, 0x60, 0x7c,
  0x60, 0x60, 0x7e, 0x00, 0x00, 0x7e, 0x60, 0x7c, 0x60, 0x60, 0x60, 0x00,
  0x00, 0x3e, 0x60, 0x60, 0x6e, 0x66, 0x3e, 0x00, 0x00, 0x66, 0x66, 0x7e,
  0x66, 0x66, 0x66, 0x00, 0x00, 0x7e, 0x18, 0x18, 0x18, 0x18, 0x7e, 0x00,
  0x00, 0x06, 0x06, 0x06, 0x06, 0x66, 0x3c, 0x00, 0x00, 0x66, 0x6c, 0x78,
  0x78, 0x6c, 0x66, 0x00, 0x00, 0x60, 0x60, 0x60, 0x60, 0x60, 0x7e, 0x00,
  0x00, 0x63, 0x77, 0x7f, 0x6b, 0x63, 0x63, 0x00, 0x00, 0x66, 0x76, 0x7e,
  0x7e, 0x6e, 0x66, 0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x00,
  0x00, 0x7c, 0x66, 0x66, 0x7c, 0x60, 0x60, 0x00, 0x00, 0x3c, 0x66, 0x66,
  0x66, 0x6c, 0x36, 0x00, 0x00, 0x7c, 0x66, 0x66, 0x7c, 0x6c, 0x66, 0x00,
  0x00, 0x3c, 0x60, 0x3c, 0x06, 0x06, 0x3c, 0x00, 0x00, 0x7e, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x66, 0x7e, 0x00,
  0x00, 0x66, 0x66, 0x66, 0x66, 0x3c, 0x18, 0x00, 0x00, 0x63, 0x63, 0x6b,
  0x7f, 0x77, 0x63, 0x00, 0x00, 0x66, 0x66, 0x3c, 0x3c, 0x66, 0x66, 0x00,
  0x00, 0x66, 0x66, 0x3c, 0x18, 0x18, 0x18, 0x00, 0x00, 0x7e, 0x0c, 0x18,
  0x30, 0x60, 0x7e, 0x00, 0x00, 0x1e, 0x18, 0x18, 0x18, 0x18, 0x1e, 0x00,
  0x00, 0x40, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x00, 0x00, 0x78, 0x18, 0x18,
  0x18, 0x18, 0x78, 0x00, 0x00, 0x08, 0x1c, 0x36, 0x63, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0x00, 

  0x00, 0x18, 0x3c, 0x7e, 0x7e, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x3c, 0x06,
  0x3e, 0x66, 0x3e, 0x00, 0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x7c, 0x00,
  0x00, 0x00, 0x3c, 0x60, 0x60, 0x60, 0x3c, 0x00, 0x00, 0x06, 0x06, 0x3e,
  0x66, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x3c, 0x66, 0x7e, 0x60, 0x3c, 0x00,
  0x00, 0x0e, 0x18, 0x3e, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x3e, 0x66,
  0x66, 0x3e, 0x06, 0x7c, 0x00, 0x60, 0x60, 0x7c, 0x66, 0x66, 0x66, 0x00,
  0x00, 0x18, 0x00, 0x38, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x06, 0x00, 0x06,
  0x06, 0x06, 0x06, 0x3c, 0x00, 0x60, 0x60, 0x6c, 0x78, 0x6c, 0x66, 0x00,
  0x00, 0x38, 0x18, 0x18, 0x18, 0x18, 0x3c, 0x00, 0x00, 0x00, 0x66, 0x7f,
  0x7f, 0x6b, 0x63, 0x00, 0x00, 0x00, 0x7c, 0x66, 0x66, 0x66, 0x66, 0x00,
  0x00, 0x00, 0x3c, 0x66, 0x66, 0x66, 0x3c, 0x00, 0x00, 0x00, 0x7c, 0x66,
  0x66, 0x7c, 0x60, 0x60, 0x00, 0x00, 0x3e, 0x66, 0x66, 0x3e, 0x06, 0x06,
  0x00, 0x00, 0x7c, 0x66, 0x60, 0x60, 0x60, 0x00, 0x00, 0x00, 0x3e, 0x60,
  0x3c, 0x06, 0x7c, 0x00, 0x00, 0x18, 0x7e, 0x18, 0x18, 0x18, 0x0e, 0x00,
  0x00, 0x00, 0x66, 0x66, 0x66, 0x66, 0x3e, 0x00, 0x00, 0x00, 0x66, 0x66,
  0x66, 0x3c, 0x18, 0x00, 0x00, 0x00, 0x63, 0x6b, 0x7f, 0x3e, 0x36, 0x00,
  0x00, 0x00, 0x66, 0x3c, 0x18, 0x3c, 0x66, 0x00, 0x00, 0x00, 0x66, 0x66,
  0x66, 0x3e, 0x0c, 0x78, 0x00, 0x00, 0x7e, 0x0c, 0x18, 0x30, 0x7e, 0x00,
  0x00, 0x18, 0x3c, 0x7e, 0x7e, 0x18, 0x3c, 0x00, 0x18, 0x18, 0x18, 0x18,
  0x18, 0x18, 0x18, 0x18, 0x00, 0x7e, 0x78, 0x7c, 0x6e, 0x66, 0x06, 0x00,
  0x08, 0x18, 0x38, 0x78, 0x38, 0x18, 0x08, 0x00, 0x10, 0x18, 0x1c, 0x1e,
  0x1c, 0x18, 0x10, 0x00
};
unsigned int atari_font_len = 1024;
