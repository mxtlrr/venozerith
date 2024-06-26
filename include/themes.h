/* Another INI parser. Too lazy to write a huge ini parser and use it twice
 * so I'm just gonna write two different ones that do the same thing. Also
 * just lazy to refactor hundreds of lines of code. */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <raylib.h>

typedef struct {
  Color primary_text;     // Focused text (Tab, Active indicator, GUI text, etc.)
  Color nonfocused_text;  // Stuff like the text that isn't focused.
  Color background;       // Self explanatory
} theme_t;

// Hex format is 0xRRGGBB. Alpha channel is always 1.
Color hex2color(__uint32_t hex);
unsigned int color2hex(Color c);

extern theme_t default_themes[2];
theme_t get_theme(char* file);
theme_t set_theme(theme_t new);

// Are we using a default theme?
bool using_default_theme(theme_t current_theme);
int which_theme(theme_t current_theme);