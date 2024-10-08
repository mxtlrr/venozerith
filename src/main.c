#include <raylib.h>
#include <stdio.h>

#include "audio.h"

void _(){}

int current_tab = 0;
char* tabs[] = {
	"Reserved", "Keybinds", "MIDI Editor",
	"Sandbox", "Reserved"
};

int main(void){
  SetTraceLogCallback(_);

	find_samples("/home/nick/music/hof");

  InitWindow(800, 600, "Venozerith");
  SetTargetFPS(240); // Eventually change this

  while(!WindowShouldClose()){
		// Tab swapping.
		int get_k = GetKeyPressed();
		if(get_k >= 49 && get_k <= 54){
			current_tab = (get_k - 48);
		}

    BeginDrawing();
			// TODO: stuff for specific tabs


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
