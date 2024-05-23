#include <raylib.h>
#include <stdio.h>
#include <math.h>

Sound sounds[1360] = { 0 }; // 240 - 1600.

#define TRACK_LEN 0.38f

int currentSound = 0;
void _(){}

// Finds the delay required between each drum hit.
// Input
//      -> BPM, beats per minute
int findDelaySec(int bpm){
    return round(1000/round(((bpm/60)*(1/TRACK_LEN))));
}

int main(void){
    char* VERSION = "0.0.1";

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
            int DelayMillisec = findDelaySec(bpm);
            float delay = (float)((float)DelayMillisec/1000);

            #ifdef DEBUG
                printf("BPM: %d | DELAY (ms): %d | WAITING: %.5f\n", bpm, DelayMillisec, delay);
            #endif

            // This is why we do above 240 BPM. I'm not a big fan of
            // delays.
            WaitTime(delay);
            PlaySound(sounds[currentSound]);
            currentSound++;

            // Reset
            if(currentSound >= 1360) currentSound = 0;
        }
        BeginDrawing();
            ClearBackground(WHITE);
            DrawText(TextFormat("BPM: %d\n%s", bpm, playing), 10, 10, 20, BLACK);
            DrawText(TextFormat("Venozerith v%s", VERSION), 10, 230, 10, GRAY);
        EndDrawing();
    }
    for (int i = 1; i < 1360; i++)
        UnloadSoundAlias(sounds[i]);     // Unload sound aliases
    UnloadSound(sounds[0]);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}