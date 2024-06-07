#include <raylib.h>
#include <stdio.h>


#include "version.h"
#include "keybindings.h"
#include "config.h"
#include "sound/sound.h"

char* tabs[] = { "Reserved", "Manual Sounds", "MIDI Editor", "Settings" };

void _(){}
int main(void) {
	SetTraceLogCallback(_); // Disable trace log callback

	InitWindow(640, 480, TextFormat("Venozerith - v%s", VERSION));
	InitAudioDevice();
	SetTargetFPS(60); // Don't overdraw stuff.

	char* test = data_from_file("keys.ini");
	keybinding_arr k = get_keybinds(test);

	sounds_t s = loadSounds();

	int tab = 1; // Current tab we're on

	while(!WindowShouldClose()){
		
		// Stupid code to change tabs
		if(IsKeyPressed(KEY_ONE)) tab = 1;
		if(IsKeyPressed(KEY_TWO)) tab = 2;
		if(IsKeyPressed(KEY_THREE)) tab = 3;

		BeginDrawing();
			ClearBackground(WHITE);
			DrawText(TextFormat("TAB: %d [%s]", tab, tabs[tab]), 10, 10, 20, BLACK);

			switch(tab){
				// Play live
				case 1:
					// Active indicator
					DrawText("1", 10, 450, 20, BLACK);
					DrawText("2", 30, 450, 20, GRAY);
					DrawText("3", 55, 450, 20, GRAY);

					// Snare
					if(IsKeyPressed(k.keys[0].key)) {
						PlaySound(s.sounds[0]);
					}
					
					// Hi-hat
					if(IsKeyPressed(k.keys[1].key)) {
						PlaySound(s.sounds[1]);
					}

					// Kick
					if(IsKeyPressed(k.keys[2].key)) {
						PlaySound(s.sounds[2]);
					}
					break;

				// MIDI Editor
				case 2:
					// Active indicator
					DrawText("1", 10, 450, 20, GRAY);
					DrawText("2", 30, 450, 20, BLACK);
					DrawText("3", 55, 450, 20, GRAY);

					// TODO:
					break;

				// Show keybindings
				case 3:
					// Active indicator
					DrawText("1", 10, 450, 20, GRAY);
					DrawText("2", 30, 450, 20, GRAY);
					DrawText("3", 55, 450, 20, BLACK);

					int starting_y = 50;
					for(int i = 0; i < 3; i++) {
						DrawText(TextFormat("Key \"%c\" - Action: %s",
												keys[(k.keys[i].key)],
												get_action_from_num(k.keys[i].action)), 50,
												starting_y, 20, BLACK);
						starting_y += 30;
					}
					break;
			}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}