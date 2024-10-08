#include "keys/cfg.h"

// TODO: be able to add more of these.
// Also.
// TODO: the find_files() function probably does it alphabetically.
// meaning that the way we do it, if you name your samples like snare.mp3, etc,
// then cymbal would be in the place of the snare.
uint8_t sc[4]  = { 0, 0, 0, 0 };
char* table[4] = { "Snare", "Kick", "Cymbal", "Hi-hat" };

void parse_keybinds(void){
	FILE* fp; uint8_t* buffer = 0; long int size = 0;
	fp = fopen("config.cfg", "r");
	if(!fp) exit(2);

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	buffer = malloc(size+1);
	if(!buffer) exit(3);

	fread(buffer, size, 1, fp);
	fclose(fp);

	// Kinda stupid but its okay for now
	uint8_t z = 0;
	for(int i = 0; i < size; i+=2) {
		sc[z] = (buffer[i]-32);
		z++;
	}
}
