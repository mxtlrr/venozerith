#include <raylib.h>
#include <stdio.h>

#include "keys/cfg.h"
#include "audio.h"

void _(){}

#define RESERVED1 1	// TODO
#define KEYBINDS  2
#define MIDI_ED   3
#define SANDBOX   4
#define RESERVED2 5	// TODO

int current_tab = 1;
char* tabs[] = {
	"Reserved", "Keybinds", "MIDI Editor",
	"Sandbox", "Reserved"
};

int main(void){
  SetTraceLogCallback(_);

	// Find samples in the samples directory
	find_samples("samples");

	// Get user keybindings
	parse_file("config.ini");
	printf("[+] INI file loaded. %d tags with %d total keys.\n", ini_tag_ct,
				ini_key_ct);
	parse_keybinds();

  InitWindow(800, 600, "Venozerith");
	InitAudioDevice();
  SetTargetFPS(240); // Eventually change this

	
	// Load every single sound
	Sound snds[256];
	for(int i = 0; i < 6; i++){
		snds[i] = LoadSound(samples[i].ident);
		if(strcmp(samples[i].ident, "") != 0){
			printf("[+] loaded sample \"%s\" at index %d\n", samples[i].ident, i);
		}
	}

  while(!WindowShouldClose()){
		// Tab swapping.
		int get_k = GetKeyPressed();
		if(get_k >= 49 && get_k <= 54){
			current_tab = (get_k - 48);
		}


    BeginDrawing();

			// Individual stuff.
			switch(current_tab){
				case KEYBINDS:
					int y = 40;
					for(int i = 0; i < 4; i++){
						DrawText(TextFormat("%c - %s", sc[i], table[i]), 50, y, 20, BLACK);
						y += 20;
					}
					break;

				case SANDBOX:
					// TODO: open a thread each time a key is pressed so you don't get
					// the weird cut off. Works for now.
					for(int i = 0; i < 4; i++)
						if(IsKeyPressed(sc[i])) PlaySound(snds[i]);
					break;
			}

			// Draw the tabs (indicator)
			int q = 10;
			for(int i = 0; i < 5; i++){
				if(current_tab == i+1) DrawText(TextFormat("%s", tabs[i]), q, 10, 20, BLACK);
				else DrawText(TextFormat("%s", tabs[i]), q, 10, 20, GRAY);
				q += 140;
			}

      // Status bar
      DrawText(TextFormat("git-%s", GIT_HASH), 10, 580, 10, BLACK);
      ClearBackground(WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
