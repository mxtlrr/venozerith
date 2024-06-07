#include <raylib.h>
#include <stdio.h>

#include "version.h"

char* tabs[] = { "Reserved", "Manual Sounds", "MIDI Editor", "Settings" };

void _(){}
int main(void) {
	SetTraceLogCallback(_); // Disable trace log callback

	InitWindow(640, 480, TextFormat("Venozerith - v%s", VERSION));
	SetTargetFPS(60); // Don't overdraw stuff.

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
				// TODO...
			}
		EndDrawing();
	}

	CloseWindow();
	return 0;
}