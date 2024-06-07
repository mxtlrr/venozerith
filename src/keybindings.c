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