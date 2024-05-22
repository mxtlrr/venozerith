#include <raylib.h>
#include <stdio.h>
void _(){}
int main(void){
    SetTraceLogCallback(_);
    InitWindow(300, 250, "Venozerith Drum Minion");
    SetTargetFPS(60);

    int bpm = 240;
    bool playing_sound = false;

    while(!(WindowShouldClose())){
        // A - increase by 10
        // D - decrease by 10
        if(bpm <= 1610) if(IsKeyPressed(KEY_A)) bpm+=10; // Upper bound
        if(bpm >= 250)  if(IsKeyPressed(KEY_D)) bpm-=10; // Lower bound

        // Play?
        if(IsKeyPressed(KEY_X)) playing_sound = !playing_sound;
        char* playing = playing_sound ? "Playing" : "Not playing";

        // TODO: get a snare sound effect and play it.
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText(TextFormat("BPM: %d\n%s", bpm, playing), 10, 10, 20, BLACK);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}