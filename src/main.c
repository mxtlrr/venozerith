#include <raylib.h>
#include <stdio.h>

Sound sounds[1360] = { 0 }; // 240 - 1600.
int currentSound = 0;
void _(){}

int main(void){
    SetTraceLogCallback(_);
    InitWindow(300, 250, "Venozerith Drum Minion");
    InitAudioDevice();

    SetTargetFPS(60);

    // load all the sounds
    sounds[0] = LoadSound("src/res/audio.mp3");
    //// alias
    for(int i = 1; i < 1360; i++){
        sounds[i] = LoadSoundAlias(sounds[0]);
    }
    currentSound = 0;

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

        if(playing_sound){
            PlaySound(sounds[currentSound]);
            // TODO: get BPM and wait however many seconds between each hit
            currentSound++;

            // Reset
            if(currentSound >= 1360) currentSound = 0;
        }
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText(TextFormat("BPM: %d\n%s", bpm, playing), 10, 10, 20, BLACK);
        EndDrawing();
    }
    for (int i = 1; i < 1360; i++)
        UnloadSoundAlias(sounds[i]);     // Unload sound aliases
    UnloadSound(sounds[0]);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}