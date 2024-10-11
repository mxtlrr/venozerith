#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

// Each tag has multiple keys
typedef struct {
	char ident[30];		// Identifier of the tag
	char value[256];  // Value. Will always be a string
} ini_key_t;

// Each tag has two parts, the identifier and the keys
typedef struct {
	char ident[30];
	ini_key_t keys[100];
} tag_t;

extern int ini_tag_ct;
extern int ini_key_ct;

// Finds the first occurrence of 'z' in 'n'
int find_first_occur(char* n, char z);

// Get the information at tags[index]. Returns the tag struct.
tag_t get_tag(uint8_t index);

// Parse the INI file and populate the tags array.
void parse_file(char* path_to_ini);
