#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

extern uint8_t sc[4];
extern char* table[4]; // 1-to-1 correspondence with sc.

void parse_keybinds(void);
