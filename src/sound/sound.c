#include "sound/sound.h"

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
  s.sounds[0] = LoadSound("config/samples/snare.mp3");
  s.sounds[1] = LoadSound("config/samples/hihat.mp3");
  s.sounds[2] = LoadSound("config/samples/kick.mp3");
  return s;
}