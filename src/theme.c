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

void load_from_ini(void){
  tag_t s = get_tag(1);
  for(int i = 0; i < 100; i++){
    if(s.keys[i].ident[0] == 0);
    else {
      uint32_t color = strtoul(s.keys[i].value, NULL, 16);
      char* id = s.keys[i].ident;

      if(strcmp(id, "active") == 0) palette[0] = color;
      if(strcmp(id, "foreground") == 0) palette[1] = color;
      if(strcmp(id, "inactive") == 0) palette[2] = color;
      if(strcmp(id, "background") == 0) palette[3] = color; 
    }
  }
}