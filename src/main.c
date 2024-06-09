#include <raylib.h>
#include <stdio.h>


#include "version.h"
#include "keybindings.h"
#include "sound/sound.h"
#include "frames.h"

#include "config.h"
#include "themes.h"

#include "tabs/midi.h"
#include "tabs/midi-frontend.h"

char* tabs[] = { "Reserved", "Manual Sounds", "MIDI Editor", "Settings" };

void _(){}
int main(void) {
	theme_t theme = get_theme("config/themes.ini");
	set_arrow_loc(50,70);

	SetTraceLogCallback(_); // Disable trace log callback

	InitWindow(640, 480, TextFormat("Venozerith - v%s", VERSION));
	InitAudioDevice();
	SetTargetFPS(1000);

	char* test = data_from_file("config/keys.ini");
	keybinding_arr k = get_keybinds(test);

	sounds_t s = loadSounds();

	int tab = 1; // Current tab we're on
	while(!WindowShouldClose()){
		
		// Stupid code to change tabs
		if(IsKeyPressed(KEY_ONE)) tab = 1;
		if(IsKeyPressed(KEY_TWO)) tab = 2;
		if(IsKeyPressed(KEY_THREE)) tab = 3;
		if(IsKeyPressed(KEY_FOUR)) tab = 4;
		

		BeginDrawing();
			ClearBackground(theme.background);
			DrawText(TextFormat("TAB: %d", tab), 10, 10, 20, theme.primary_text);

			switch(tab){
				// Play live
				case 1:
					// Active indicator
					DrawText(tabs[1], 10, 450, 20, theme.primary_text);
					DrawText(tabs[2], 175, 450, 20, theme.nonfocused_text);
					DrawText(tabs[3], 300, 450, 20, theme.nonfocused_text);

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
					DrawText(tabs[1], 10, 450, 20, theme.nonfocused_text);
					DrawText(tabs[2], 175, 450, 20, theme.primary_text);
					DrawText(tabs[3], 300, 450, 20, theme.nonfocused_text);

					// TODO:
					GrabInput(k,s);
					DrawMIDI();
					break;

				// Show keybindings
				case 3:
					// Active indicator
					DrawText(tabs[1], 10, 450, 20, theme.nonfocused_text);
					DrawText(tabs[2], 175, 450, 20, theme.nonfocused_text);
					DrawText(tabs[3], 300, 450, 20, theme.primary_text);

					int starting_y = 50;
					for(int i = 0; i < 3; i++) {
						DrawText(TextFormat("Key \"%c\" - Action: %s",
												keys[(k.keys[i].key)],
												get_action_from_num(k.keys[i].action)), 50,
												starting_y, 20, theme.primary_text);
						starting_y += 30;
					}
					break;
			}

		DrawText(TextFormat("%.4d", getframes()), 510, 450, 20, theme.nonfocused_text);
		EndDrawing();


		setframes(getframes() + 1);
	}
	
	for(int i = 0; i < 3; i++){
		UnloadSound(s.sounds[i]);
	}
	CloseAudioDevice();
	CloseWindow();
	return 0;
}