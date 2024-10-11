#pragma once

#include <stdio.h>
#include <stdint.h>

#include <raylib.h>

#include "keys/ini.h"

extern uint32_t palette[4];
extern char* palette_descriptors[4];

Color rgb_to_color(uint32_t c);
uint32_t col_to_rgb(Color c);

// Loads the theme from the configuration file
void load_from_ini(void);