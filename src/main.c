#include <raylib.h>
#include <stdio.h>

#include "keys/cfg.h"
#include "theme.h"
#include "audio.h"

#define ARRL(x) (sizeof(x)/(sizeof(x[0])))

void _(){}

#define SANDBOX   1
#define KEYBINDS  2
#define MIDI_ED   3
#define THEMES    4
int current_tab = 1;
char* tabs[] = {
	"Sandbox", "Keybinds", "MIDI Editor", "Themes"
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
	
	// Update theme, and make changes if needed.
	load_from_ini();

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
						DrawText(TextFormat("%c - %s", sc[i], table[i]), 50, y, 20,
											rgb_to_color(palette[1]));
						y += 20;
					}
					break;

				case SANDBOX:
					for(int i = 0; i < 4; i++)
						if(IsKeyPressed(sc[i])) PlaySound(snds[i]);
					break;

				case THEMES:
					y = 40;
					for(int i = 0; i < (int)ARRL(palette); i++){
						DrawText(TextFormat("%s: #%.6x",
								palette_descriptors[i], palette[i]), 50, y, 20,
								rgb_to_color(palette[1]));
						y+=20;
					}
					break;
			}

			// Draw the tabs (indicator)
			int q = 10;
			for(int i = 0; i < (int)ARRL(tabs); i++){
				if(current_tab == i+1) DrawText(TextFormat("%s", tabs[i]), q, 10, 20,
						rgb_to_color(palette[0]));
				else DrawText(TextFormat("%s", tabs[i]), q, 10, 20,
							rgb_to_color(palette[2]));
				q += 140;
			}

      // Status bar
      DrawText(TextFormat("git-%s", GIT_HASH), 10, 580, 10, rgb_to_color(palette[1]));
      ClearBackground(rgb_to_color(palette[3]));
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
