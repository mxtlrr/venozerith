#include "sound/find-sounds.h"

int counter = 0;

result_t findSounds(char* directory){
  counter = 0;
  result_t r;
  for(int i = 0; i < 256; i++) r.r[i] = NULL;
  #ifdef __unix__
    struct dirent* de;
    DIR* dr = opendir(directory);

    if(!dr){
      result_t bad = {.r = NULL };
      printf("[!] Cannot open directory %s.\n", directory);
      return bad;
    }

    while((de = readdir(dr)) != NULL && (counter != 256 || counter <= 256)){
      if(strcmp(de->d_name, ".") == 0);
      else {
        if(strcmp(de->d_name, "..") == 0);
        else r.r[counter] = de->d_name;
      }
      counter++;
    }

    return r;
  #endif

  // I don't know
}