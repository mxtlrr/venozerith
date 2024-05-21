#include <raylib.h>
#include <stdio.h>
void _(){}
int main(void){
    SetTraceLogCallback(_);
    InitWindow(300, 250, "Venozerith Drum Minion");
    SetTargetFPS(60);

    while(!(WindowShouldClose())){
        BeginDrawing();
            ClearBackground(WHITE);
        EndDrawing();
    }
    CloseWindow();
    return 0;
}