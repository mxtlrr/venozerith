/* Shitty INI parser. */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "keybindings.h"

#define FILE_LENGTH 50  // Max length of the file
char* data_from_file(char* filepath);

typedef struct {
  keybinding_t keys[3];
} keybinding_arr; // No good very bad.
keybinding_arr get_keybinds(char* data);