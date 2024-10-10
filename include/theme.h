#pragma once

#include <stdio.h>
#include <stdint.h>

#include <raylib.h>

extern uint32_t palette[4];
extern char* palette_descriptors[4];

Color rgb_to_color(uint32_t c);
uint32_t col_to_rgb(Color c);