#include "keys/cfg.h"

// TODO: be able to add more of these.
// TODO: the find_files() function probably does it alphabetically.
// meaning that the way we do it, if you name your samples like snare.mp3, etc,
// then cymbal would be in the place of the snare.
uint8_t sc[4]  = { 0, 0, 0, 0 };
char* table[4] = { "Snare", "Kick", "Cymbal", "Hi-hat" };

void parse_keybinds(void){
	tag_t n = get_tag(0);		// DRUMS is tag 0.
	if(strcmp(n.ident, "drums") != 0){
		fprintf(stderr, "[:(] Tag 0 for INI file must be \"drums\", however, it's set to \"%s\".\n", n.ident);
		exit(1);
	}

	for(int i = 0; i < 100; i++){
		if(n.keys[i].ident[0] == 0);
		else {
			// This makes sure that we don't care about the order.
			char* key = n.keys[i].ident;
			char scan_code = (n.keys[i].value[0])-32;

			// FIXME: this code is yuck. But it works. Eventually fix this?
			if(strcmp(key, "snare") == 0) sc[0] = scan_code;
			if(strcmp(key, "kick") == 0) sc[1] = scan_code;
			if(strcmp(key, "cymbal") == 0) sc[2] = scan_code;
			if(strcmp(key, "hihat") == 0) sc[3] = scan_code;
		}
	}
}
