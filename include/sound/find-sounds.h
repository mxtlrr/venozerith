/* Find sounds in some directory. */
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __unix__
  #include <dirent.h>
#endif // TODO: support windows.

typedef struct {
  char* r[256];
}result_t;

// Returns 256 item array, each having the RELATIVE
// directory, i.e. config/sounds/snare.mp3
result_t findSounds(char* directory);