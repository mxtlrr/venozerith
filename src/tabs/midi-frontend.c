#include "tabs/midi-frontend.h"

user_details_t main_details = {
  .code = 1,      // 1st position of
  .track = 1,     // the 1st track.
};

int bpm = 240;


track_t track1 = { .bpm = 0, .codes = "---------------" };
track_t track2 = { .bpm = 0, .codes = "---------------" };
track_t track3 = { .bpm = 0, .codes = "---------------" };

bool playing = false;

void GrabInput(keybinding_arr k, sounds_t s){
  // Change track
  if(IsKeyPressed(KEY_DOWN) && (main_details.track < 3))  main_details.track++;
  if(IsKeyPressed(KEY_UP)   && (main_details.track > 1))  main_details.track--;

  // Move back and forth in codes
  if(IsKeyPressed(KEY_LEFT)  && (main_details.code > 1))  main_details.code--;
  if(IsKeyPressed(KEY_RIGHT) && (main_details.code < 15)) main_details.code++;

  // Set current location
  // TODO: Refactor this code.
  if(IsKeyPressed(k.keys[0].key)){
    switch(main_details.track){
      case TRACK1: 
        track1.codes[main_details.code-1] = SNARE;
        break;
      case TRACK2:
        track2.codes[main_details.code-1] = SNARE;
        break;
      case TRACK3:
        track3.codes[main_details.code-1] = SNARE;
        break;
    }
  } else if(IsKeyPressed(k.keys[1].key)){
    switch(main_details.track){
      case TRACK1:
        track1.codes[main_details.code-1] = HIHAT;
        break;
      case TRACK2: 
        track2.codes[main_details.code-1] = HIHAT;
        break;
      case TRACK3:
        track3.codes[main_details.code-1] = HIHAT;
        break;
    }
  } else if(IsKeyPressed(k.keys[2].key)){
    switch(main_details.track){
      case TRACK1:
        track1.codes[main_details.code-1] = KICK;
        break;
      case TRACK2: 
        track2.codes[main_details.code-1] = KICK;
        break;
      case TRACK3:
        track3.codes[main_details.code-1] = KICK;
        break;
    }
  }
  
  if(IsKeyPressed(KEY_BACKSPACE)){ // Remove something from current value
    switch(main_details.track){
      case TRACK1: 
        track1.codes[main_details.code-1]=NOTHING;
        break;
      case TRACK2:
        track2.codes[main_details.code-1]=NOTHING;
        break;
      case TRACK3:
        track3.codes[main_details.code-1]=NOTHING;
        break;
    }
  }

  // TODO: Let lower bound be configurable.
  if(IsKeyPressed(KEY_MINUS) && (bpm > LOWER_BOUND)) bpm -= 10;
  if(IsKeyPressed(KEY_EQUAL) && (bpm < UPPER_BOUND)) bpm += 10;

  if(IsKeyPressed(KEY_P)) playing = !playing;
  if(playing){
    midi_t midi = make_midi_from_tracks(track1,track2,track3);
    play_midi(midi, s);

    // Don't replay
    playing = false;
  }
  // TODO: implement playing
}

void DrawMIDI(){
  // Set bpm of tracks
  track1.bpm=bpm;track2.bpm=bpm;track3.bpm=bpm;

  DrawText(TextFormat("Track %d, Code %d | Playing MIDI? %s | BPM=%d",
            main_details.track, main_details.code,
            playing ? "Yes" : " No", bpm), 50, 50, 20, BLACK);

  // Draw each track
  DrawText(TextFormat("%s", track1.codes), 50, 90, 20, BLACK);
  DrawText(TextFormat("%s", track2.codes), 50, 110, 20, BLACK);
  DrawText(TextFormat("%s", track3.codes), 50, 130, 20, BLACK);
  
}