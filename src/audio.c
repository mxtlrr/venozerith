#include "audio.h"
sample_t samples[MAX_SAMPLES];

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

			sample_ct++;
			strcpy(samples[sample_i].ident, buffer);
			samples[sample_i].index = sample_i;
			sample_i++;
		}
	}
	printf("[:)] done searching through \"%s\"...found %d samples\n", abs_path, sample_ct);
}
