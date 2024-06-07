#include <keybindings.h>

// Default keybindings.
keybinding_t keybinds[] = {
  { .action = PLAY_SNARE, .key = 83 }, // Play snare. Keybinding is  S
  { .action = PLAY_HIHAT, .key = 68 }, // Play hi-hat. Keybinding is D
  { .action = PLAY_KICK,  .key = 88 }  // Play kick. Keybinding is   X
};

char keys[] = {
  // 0 - 64 is reserved
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
  ' ', ' ', ' ', ' ', ' ',

  'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O',
  'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
};

int get_ordinal(byte key){
  int index = 0;
  for(int i = 0; i < 91; i++){
    if(keys[i] == key){
      index = i;
      break;
    }
  }
  return index;
}

char* get_action_from_num(byte action){
  switch(action){
    case PLAY_SNARE:
      return "Play Snare";
      break;
    case PLAY_HIHAT:
      return "Play Hi-Hat";
      break;
    case PLAY_KICK:
      return "Play Kick";
      break;
  }
  return "Unknown";
}


void set_action(byte action, byte key){
  switch(action){
    case PLAY_SNARE:
      keybinds[0].key = key;
      break;
    case PLAY_HIHAT:
      keybinds[1].key = key;
      break;
    case PLAY_KICK:
      keybinds[2].key = key;
      break;
  }
}