#include "sound/sound.h"

// Order:
// Snare, Hi-hat, Kick
float lengths[3] = {
  0.38f, 1.98f, 1.98f
};

int get_len(int bpm, float sound_len){
  return round(1000/round(((bpm/60)*(1/sound_len))));
}


sounds_t loadSounds(){
  sounds_t s = { 0 };
  s.sounds[0] = LoadSound("src/samples/snare.mp3");
  s.sounds[1] = LoadSound("src/samples/hihat.mp3");
  s.sounds[2] = LoadSound("src/samples/kick.mp3");
  return s;
}