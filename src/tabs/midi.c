#include "tabs/midi.h"

midi_t make_midi_from_tracks(track_t track1, track_t track2, track_t track3){
  track_t empty2 = {.bpm = 0x00, .codes = 0};
  midi_t empty = { .bpm = 0, .tracks = {empty2,empty2,empty2} };

  if(track1.bpm != track2.bpm && track2.bpm != track3.bpm){
    return empty;
  }
  midi_t z = { .bpm = track1.bpm,
                .tracks = {
                track1, track2, track3
                }};
  return z;
}

void play_midi(midi_t midi, sounds_t sounds){
  track_t traxx[3] = { midi.tracks[0],
                       midi.tracks[1],
                       midi.tracks[2] };

  // We have the three tracks.
  float kick_delay = get_len(traxx[0].bpm, 2);

  char cool[15][3] = { {0} };
  // Set up our stuff
  for(int i = 0; i < 15; i++){
    cool[i][0] = traxx[0].codes[i];
    cool[i][1] = traxx[1].codes[i];
    cool[i][2] = traxx[2].codes[i];
  }

  // Now we play the sound
  // FIXME: Don't use Sleep()
  for(int i = 0; i < 15; i++){
    for(int j = 0; j < 3; j++){
      // printf("%c\n", cool[i][j]);
      switch(cool[i][j]){
        case 'S':
          PlaySound(sounds.sounds[0]);
          // printf("Ok");
          break;
        case 'H':
          PlaySound(sounds.sounds[1]);
          break;
        case 'K':
          PlaySound(sounds.sounds[2]);
          break;
        case '-':
          break;
      }
    }
    int delay_msec = get_len(traxx[0].bpm, (float)kick_delay);
    printf("Track BPM -> %d | ", traxx[0].bpm);
    float delay = (float)((float)delay_msec/1000);
    printf("Delay (ms) is %f\n", delay);

    WaitTime(delay/1000); // Don't wait hundreds of seconds lmao
  }
}