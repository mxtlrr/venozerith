#include "config.h"

char* data_from_file(char* filepath){
  FILE* fp = fopen(filepath, "r");
  if(!fp) {
    // TODO: if on windows, use MessageBox
    fprintf(stderr, "Couldn't open file: %s\n", filepath);
    exit(1);
  
  }
  long file_length = 0;             // Length of the file
  fseek(fp, 0, SEEK_END);           // Go to the end of the file
  file_length = ftell(fp);
  rewind(fp);                       // Go back

  char* buffer = (char*)malloc(file_length * sizeof(char));
  int p = fread(buffer, file_length, 1, fp);
  if (p != 1) { // Nothing read
    fprintf(stderr, "Failed to fread()\n");
  }
  fclose(fp);         // Close file pointer.
  return buffer;

}

keybinding_arr get_keybinds(char* data){

  // Parse the data
  char* token = strtok(data, "\n"); // Get first token

  char* tokens[4] = { 0 };
  size_t total_length = 0;

  for(int i = 0; token != NULL; i++){
    total_length += strlen(token) + 1;
  
    tokens[i] = token;
    token = strtok(NULL, "\n");
  }

  /* We use i=1 to skip the [options] */
  int index = 0;
  char* tokens_space[9] = { 0 };

  for(int i = 1; i < 4; i++){
    char* token2 = strtok(tokens[i], " ");
    for(int j = 0; token2 != NULL; j++){
      tokens_space[index] = token2;
      token2 = strtok(NULL, " ");
      index++;
    }
  }

  keybinding_arr k = { 0 };
  for(int i = 0; i < 9; i++){
    if(strcmp(tokens_space[i], "snare") == 0){
      // Then we are using the snare
      k.keys[0].action = PLAY_SNARE;
      k.keys[0].key = get_ordinal(tokens_space[i+2][1]);
    }

    if(strcmp(tokens_space[i], "hihat") == 0){
      k.keys[1].action = PLAY_HIHAT;
      k.keys[1].key = get_ordinal(tokens_space[i+2][1]);
    }

    if(strcmp(tokens_space[i], "kick") == 0){
      k.keys[2].action = PLAY_KICK;
      k.keys[2].key = get_ordinal(tokens_space[i+2][1]);
    }    
  }

  return k; // Access via k.keys.
            // Stupid practice tbh.
}