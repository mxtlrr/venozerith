/* Frontend for MIDI stuff. Responsible for drawing stuff,
 * aswell as getting input. */
#pragma once

#include <raylib.h>
#include <stdio.h>
#include <stdint.h>

#include "tabs/midi.h"
#include "config.h"

typedef struct {
  unsigned char code;   // 1 - 15 (or 16?)
  unsigned char track;  // 1 - 3
} user_details_t;

extern user_details_t main_details;
extern bool playing;                // Are we playing the MIDI?

// Called each frame. Checks for input and modifies user details,
// defined as main_details.
void GrabInput(keybinding_arr k, sounds_t s);

// Meat and potatoes, draws everything to the screen.
void DrawMIDI(int bpm);