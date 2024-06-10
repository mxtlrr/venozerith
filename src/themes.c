#include "themes.h"

Color hex2color(unsigned int hex){
  // 0xFF DB CF
  //   ^^ ^^ ^^
  //   R  G  B
  Color a = { .r = (hex>>16) & 0xff,
              .g = (hex>>8)  & 0xff,
              .b = hex & 0xff,
              .a = 0xff};
  return a;
}


theme_t get_theme(char* file){
  FILE* fp = fopen(file, "rb");
  if(!fp){
    printf("[!!] I could not load file %s\n", file);
    exit(2);
  } else {
    printf("[+] Loaded %s\n", file);
  }

  // Get the length of the file
  long len = 0;
  fseek(fp,0,SEEK_END);
  len = ftell(fp);
  rewind(fp);

  printf("[+] File '%s' is %ld bytes long.\n", file, len);
  
  /* Store everything in a buffer */
  char* buffer = (char*)malloc(len * sizeof(char));
  int p = fread(buffer, len, 1, fp);
  if(p != 1){
    printf("[!!] Can't fread().\n");
    exit(1);
  }

  fclose(fp);

  // Time to parse :)
  char* tok = strtok(buffer, "\n");
  
  char* tokens[4] = { 0 };
  for(int i = 0; tok != NULL; i++){
    // Put this in an array.
    // We do this to be able to split each line by spaces and parse
    // that.

    tokens[i] = tok;
    tok = strtok(NULL, "\n");
  }


  // Split by space.
  int index = 0;
  char* tokens_space[9] = { 0 };

  for(int i = 1; i < 4; i++){
    char* token2 = strtok(tokens[i], " ");
    for(int j = 0; token2 != NULL; j++){
      tokens_space[index] = token2;
      token2 = strtok(NULL, " ");
      index++;
    }
  }

  // Order: primary, nonfocused, background
  long int theme_vals[3] = { 0, 0, 0 };
  index = 0;
  for(int i=1;i<4;i++){
    int good_token = (3*i)-1;
    long int v = strtol(tokens_space[good_token], NULL, 0x10);
    theme_vals[index] = v;
    index++;
  }

  for(int i = 0; i < 3; i++){
    printf("theme[%d] = %.7ld (hex = 0x%.6lx)\n",  i, theme_vals[i], theme_vals[i]);
  }

  theme_t theme = { .primary_text    = hex2color(theme_vals[0]),
                    .nonfocused_text = hex2color(theme_vals[1]),
                    .background      = hex2color(theme_vals[2])};

  // Clean up.
  free(buffer);
  return theme;
}

/* Probably delete this idk. */
theme_t set_theme(theme_t new){
  return new;
}

unsigned int color2hex(Color c){
  __uint8_t r = c.r;
  __uint8_t g = c.g;
  __uint8_t b = c.b;

  unsigned int color = (r<<16) | (g<<8) | b;
  return color;
}


theme_t default_themes[2] = {
  { .background = (Color){255,255,255,255}, .primary_text = (Color){0,0,0,255}, .nonfocused_text = (Color){209,209,209,255}}, // Light mode
  { .background = (Color){0,0,0,255}, .primary_text = (Color){255,255,255,255}, .nonfocused_text = (Color){209,209,209,255}}  // Dark one
};

bool using_default_theme(theme_t current_theme){

  bool res = false;
  for(int i = 0; i < 2; i++){
    if(color2hex(current_theme.background) == color2hex(default_themes[i].background)
        && (color2hex(current_theme.nonfocused_text) == color2hex(default_themes[i].nonfocused_text))
        && (color2hex(current_theme.primary_text) == color2hex(default_themes[i].primary_text))){
          res = true;
          return res;
    }
  }
  return res;
}

int which_theme(theme_t current_theme){
  for(int i = 0; i < 2; i++){
    if(color2hex(current_theme.background) == color2hex(default_themes[i].background)
        && (color2hex(current_theme.nonfocused_text) == color2hex(default_themes[i].nonfocused_text))
        && (color2hex(current_theme.primary_text) == color2hex(default_themes[i].primary_text))){
          return i;
    }
  }
  return -1;
}