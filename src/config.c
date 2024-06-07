#include "config.h"

char* data_from_file(char* filepath){
  FILE* fp = fopen(filepath, "r");
  long file_length = 0;             // Length of the file
  fseek(fp, 0, SEEK_END);           // Go to the end of the file
  file_length = ftell(fp);
  rewind(fp);                       // Go back

  char* buffer = (char*)malloc(file_length * sizeof(char));
  fread(buffer, file_length, 1, fp);
  fclose(fp);         // Close file pointer.
  return buffer;

}

keybinding_arr get_keybinds(char* data){

  // Parse the data
  char* token = strtok(data, " "); // Get first token

  char* tokens[10] = { 0 };
  for(int i = 0; token != NULL; i++){
    tokens[i] = token;
    token = strtok(NULL, " ");
  }

  // Super gross code. FIXME. But it works
  char snare  = tokens[2][1];
  char hi_hat = tokens[5][1];
  char kick   = tokens[8][1];


  keybinding_arr k = { 0 };

  // Also gross code:( I wish there
  // was an easier way to do this
  k.keys[0].action = PLAY_SNARE; k.keys[0].key = get_ordinal(snare);
  k.keys[1].action = PLAY_HIHAT; k.keys[1].key = get_ordinal(hi_hat);
  k.keys[2].action = PLAY_KICK;  k.keys[2].key = get_ordinal(kick);
  
  return k; // Access via k.keys.
            // Stupid practice tbh.
}