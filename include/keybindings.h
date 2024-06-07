#pragma once
typedef unsigned char byte;

enum ACTION {
  PLAY_SNARE = 0x01,
  PLAY_HIHAT = 0x02,
  PLAY_KICK  = 0x03
};

typedef struct keybinding {
  byte key;     // Ordinal number.
  byte action;  // Technically can be one bit but that's stupid.
} keybinding_t;

extern keybinding_t keybinds[]; // Keybindings.
extern char keys[];             // The corresponding
                                // key, e.g. keys[65] = 'A'.

char* get_action_from_num(byte action);