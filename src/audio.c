#include "audio.h"
sample_t samples[MAX_SAMPLES];

int __validate_mp3(char* buffer){
	FILE* f; unsigned char* buff = 0; long int size = 0;	
	if((f = fopen(buffer, "r"))){
		fseek(f, 0, SEEK_END);
		size = ftell(f);
		fseek(f, 0, SEEK_SET);

		buff = malloc(size+1);
		if(!buff) return 1;

		fread(buff, size, 1, f);
		fclose(f);
	}

	// This is really stupid but it kinda works.
	if(buff[0x15] == 0xFF && buff[0x16] == 0xFE) return 0;
	return 1;
}

void find_samples(char* abs_path){
	// Linux only.
	struct dirent *dp;
	DIR *dfd;

	if((dfd = opendir(abs_path)) == NULL){
		printf("[:(] can't open path \"%s\"\n", abs_path);
		exit(2);
	}

	int sample_ct = 0; int sample_i = 0;
	while((dp = readdir(dfd)) != NULL){
		// Skip . and .. directories, those will never be used.
		if((strcmp(dp->d_name, ".") == 0) || (strcmp(dp->d_name, "..") == 0)){}
		else {
			char buffer[257];
			sprintf(buffer, "%s/%s", abs_path, dp->d_name);

			// Validate if it's an mp3 or not
			int v = __validate_mp3(buffer);
			if(v == 0){
				sample_ct++; // one more sample!
				// Append to our file
				strcpy(samples[sample_i].ident, dp->d_name);
				samples[sample_i].index = sample_i;
				sample_i++;
			}
		}
	}
	printf("[:)] done searching through \"%s\"...found %d samples\n", abs_path, sample_ct);
}
