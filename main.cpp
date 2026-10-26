#include "raylib.h"
#include "game.hpp"

int main()
{
    const int WIDTH = 600;
    const int HEIGHT = 600;
    Game game;
    SetTraceLogLevel(LOG_NONE);
    SetTargetFPS(30);
    InitWindow(WIDTH, HEIGHT, "window");
    while (!WindowShouldClose())
    {

        game.update();
        BeginDrawing();
        ClearBackground(BLACK);
        game.draw();
        EndDrawing();
    }
}