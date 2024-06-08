#include <raylib.h>
#include <stdio.h>


#include "version.h"
#include "keybindings.h"
#include "config.h"
#include "sound/sound.h"
#include "tabs/midi.h"

char* tabs[] = { "Reserved", "Manual Sounds", "MIDI Editor", "Settings",
								 "Snare Spam" };

Sound sounds[1360] = { 0 };

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

	bool spam_yes = false;
	int bpm = 240;
	sounds[0] = s.sounds[0];
	for(int i = 1; i < 1360; i++){
		sounds[i] = LoadSoundAlias(sounds[0]);
	}
  int currentSound = 0;
	while(!WindowShouldClose()){
		
		// Stupid code to change tabs
		if(IsKeyPressed(KEY_ONE)) tab = 1;
		if(IsKeyPressed(KEY_TWO)) tab = 2;
		if(IsKeyPressed(KEY_THREE)) tab = 3;
		if(IsKeyPressed(KEY_FOUR)) tab = 4;
		

		BeginDrawing();
			ClearBackground(WHITE);
			DrawText(TextFormat("TAB: %d", tab), 10, 10, 20, BLACK);

			switch(tab){
				// Play live
				case 1:
					// Active indicator
					DrawText(tabs[1], 10, 450, 20, BLACK);
					DrawText(tabs[2], 175, 450, 20, GRAY);
					DrawText(tabs[3], 300, 450, 20, GRAY);

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
					DrawText(tabs[1], 10, 450, 20, GRAY);
					DrawText(tabs[2], 175, 450, 20, BLACK);
					DrawText(tabs[3], 300, 450, 20, GRAY);

					// TODO:
					break;

				// Show keybindings
				case 3:
					// Active indicator
					DrawText(tabs[1], 10, 450, 20, GRAY);
					DrawText(tabs[2], 175, 450, 20, GRAY);
					DrawText(tabs[3], 300, 450, 20, BLACK);

					int starting_y = 50;
					for(int i = 0; i < 3; i++) {
						DrawText(TextFormat("Key \"%c\" - Action: %s",
												keys[(k.keys[i].key)],
												get_action_from_num(k.keys[i].action)), 50,
												starting_y, 20, BLACK);
						starting_y += 30;
					}
					break;

				// Spam drums
				case 4:
					// Active indicator
					DrawText(tabs[1], 10, 450, 20, GRAY);
					DrawText(tabs[2], 175, 450, 20, GRAY);
					DrawText(tabs[3], 300, 450, 20, GRAY);
					DrawText(tabs[4], 400, 450, 20, BLACK);

					DrawText(TextFormat("Press '%c' to start spamming (BPM=%d)\nSpamming? %s", keys[k.keys[0].key],
									bpm, spam_yes?"Yes":"No"), 50, 50, 20, BLACK);
					DrawText("\n\n\n\n+/- to increase/decrease BPM by 10", 50, 50, 20, BLACK);

					if(IsKeyPressed(get_ordinal(keys[k.keys[0].key]))) spam_yes = !spam_yes;
					if(IsKeyPressed(KEY_MINUS) && bpm > 240) bpm -= 10;
					if(IsKeyPressed(KEY_EQUAL)) bpm += 10;


					if(spam_yes){
						int dmesc = get_len(bpm, 0.38f);
						float delay = (float)((float)dmesc/1000);

						WaitTime(delay);
						PlaySound(sounds[currentSound]);
						currentSound++;
					}
			}
		EndDrawing();
	}

	for (int i = 1; i < 1360; i++)
			UnloadSoundAlias(sounds[i]);     // Unload sound aliases
	UnloadSound(sounds[0]);
	
	for(int i = 0; i < 3; i++){
		UnloadSound(s.sounds[i]);
	}
	CloseAudioDevice();
	CloseWindow();
	return 0;
}