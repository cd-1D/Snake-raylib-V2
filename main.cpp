#include "raylib.h"
#include "config.hpp"
#include "game.hpp"
int main(){
    Game game;
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(30);
    InitWindow(WIDTH, HEIGHT, "window");
    while(!WindowShouldClose()){
        
        game.update();
        BeginDrawing();
            ClearBackground(BLACK);
            game.draw();
        EndDrawing();
    }
}