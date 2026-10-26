#include "snake.hpp"
#include "raylib.h"
#include <iostream>
void Snake::update()
{
    float DT = GetFrameTime();
    timer += DT;
    if (IsKeyPressed(KEY_D))
        direction = {1, 0};
    if (IsKeyPressed(KEY_A))
        direction = {-1, 0};
    if (IsKeyPressed(KEY_W))
        direction = {0, -1};
    if (IsKeyPressed(KEY_S))
        direction = {0, 1};
    if (coolDown < timer)
    {
        positionSnake.x += speed * direction.x;
        positionSnake.y += speed * direction.y;
        timer = 0;
    }
    std::cout << timer << std::endl;
}
void Snake::draw()
{
    DrawRectangleV(positionSnake, sizeSnake, GREEN);
}