#include <raylib.h>
#include <stdio.h>

#include "audio.h"

void _(){}

int main(void){
  SetTraceLogCallback(_);

	find_samples("/home/nick/music/hof");

	return 0;
  InitWindow(800, 600, "Venozerith");
  SetTargetFPS(240); // ?

  while(!WindowShouldClose()){
    BeginDrawing();

      // Status bar
      DrawText(TextFormat("git-%s", GIT_HASH), 10, 580, 10, BLACK);
      ClearBackground(WHITE);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}
