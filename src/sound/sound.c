#include "sound/sound.h"
#include "sound/find-sounds.h"

// Order:
// Snare, Hi-hat, Kick
float lengths[3] = {
  0.38f, 1.98f, 1.98f
};

int get_len(int bpm, float sound_len){
  if(bpm <= 0 || sound_len <= 0) return -1; // Division by zero

  float bps  = bpm / 60.0f;    // How many beats per second?
  float bpsl = bps/sound_len;  // Beats in the length of sound_len

  if(bpsl != 0)
    return round(1000/bpsl);
  return -1;
}

sounds_t loadSounds(){
  sounds_t s = { 0 };
  result_t r = findSounds("config/samples");
  for(int i = 0; i < 256; i++){
    if(r.r[i] != NULL){
      s.sounds[i] = LoadSound(r.r[i]);
      printf("Loaded \"%s\" as sound %d\n", r.r[i], i);
    } else break; // No more files, what are we doing?
  }
  return s;
}