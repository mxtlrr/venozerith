/* The code for the MIDI editor. It works like this:
 * 3 tracks x 16 chars
 * When you play, the code splits it into an array with 1 character, e.g.
 * 
 * -H-
 * SH-
 * --K
 * It splits the code into the following arrays: [- S -], [H H -], [- - K]
*/
#pragma once

#include <stdio.h>
#include <raylib.h>


enum CODE_VALUES {
  SNARE = 'S',
  HIHAT = 'H',
  KICK = 'K',
  NOTHING = '-'
};

typedef struct {
  char codes[16];
} track_t;

typedef struct {
  track_t tracks[3];
  int bpm;            // Range: 120 - 380
} midi_t; // The tracks



midi_t make_midi_from_tracks(track_t track1, track_t track2, track_t track3);
void play_midi(midi_t midi);