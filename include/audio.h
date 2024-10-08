#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

// Directory stuff
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_SAMPLES 10

typedef struct {
	char ident[300];		// Identifier (this is literally just the name of the file)
	uint8_t index;		// Depends on what sample it is.
} sample_t;

extern sample_t samples[MAX_SAMPLES];

// Finds sample in a directory and populates the list of samples.
// TODO: validate if file is infact an OGG or not
void find_samples(char* abs_path);
