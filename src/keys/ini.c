#include "keys/ini.h"

tag_t tags[100];
int ini_tag_ct = 0; int ini_key_ct = 0;

int find_first_occur(char* n, char z){
  for(int i = 0; n[i] != '\0'; i++)
    if(n[i] == z) return i;
  return -1;    // Not found.
}

tag_t get_tag(uint8_t index){
  return tags[index];
}

void parse_file(char* path_to_ini){
  // read file
	FILE* fp; char* buf = 0; long int size = 0;
	fp = fopen(path_to_ini, "r");
	if(!fp){
		fprintf(stderr, "can't open file.\n");
		return;
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	buf = malloc(size);
	if(!buf){
		fprintf(stderr, "no memory to alloc %ld bytes\n", size);
		free(buf);
		return;
	}
	fread(buf, size, 1, fp);
	fclose(fp);

	// parse the ini
	char* token = 0;
	token = strtok(buf, "\n");
	while(token != NULL){
		if(token[0] != '#'){
			// get a tag
			if(token[0] == '['){ // We have a tag!!
				char nz[200];
				for(size_t i = 1; i < (strlen(token)-1); i++){
					nz[i-1] = token[i];
				}
				strcpy(tags[ini_tag_ct].ident, nz);
				ini_tag_ct++;
			}
			// now we add the keys!!
			else if(token[0] != 0 ){
				int delim = find_first_occur(token, '=');
				char value[256] = {0};

				// copy identifier
				strncpy(tags[ini_tag_ct-1].keys[ini_key_ct].ident, token, (delim-1));

				// now get the key
				int zzz = delim+2; // don't really know what to call this...
				for(size_t i = zzz; i < strlen(token); i++){
					value[i-zzz] = token[i];
				}
				strncpy(tags[ini_tag_ct-1].keys[ini_key_ct].value, value, strlen(value));
				ini_key_ct++;
			}
			
		}
		token = strtok(NULL, "\n");
	}
}