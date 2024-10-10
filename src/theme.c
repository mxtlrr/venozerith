#include "theme.h"

uint32_t palette[4] = {
  0x000000,     // Active
  0x000000,     // Foreground
  0x6e6e6e,     // Inactive
  0xFFFFFF,     // Background
};

char* palette_descriptors[4] = {
  "Active", "Foreground", "Inactive", "Background"
};

Color rgb_to_color(uint32_t c){
  return (Color){(c>>16),((c>>8) & 0xff),
    (c & 0xFF),255};
}

uint32_t col_to_rgb(Color c){
  // We don't really care about the alpha
  // channel.
  return (((c.r << 8) + c.g) << 8) + c.b;
}