#include <raylib.h>
#include <stdio.h>

#include "version.h"

void _(){}
int main(void) {
	SetTraceLogCallback(_); // Disable trace log callback

	InitWindow(640, 480, TextFormat("Venozerith - v%s", VERSION));
	SetTargetFPS(60); // Don't overdraw stuff.

	while(!WindowShouldClose()){
		BeginDrawing();
			ClearBackground(WHITE);
		EndDrawing();
	}

	CloseWindow();
	return 0;
}