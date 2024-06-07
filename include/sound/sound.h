/** Stuff for playing sound **/
#pragma once

#include <math.h>
#include <stdio.h>
#include <raylib.h>

/* Default sound lengths. */
extern float lengths[3];

// Get the delay between each sound, this is used for
// calculating how much to wait before each beat (MIDI).
int get_len(int bpm, float sound_len);

typedef struct {
  Sound sounds[3]; // Order: snare, hihat, kick
} sounds_t;

sounds_t loadSounds();