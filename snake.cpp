#include "snake.hpp"
#include "raylib.h"
#include "config.hpp"
#include <iostream>
#include <vector>
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
        bodyOld.push_back(positionSnake);
        positionSnake.x += step * direction.x;
        positionSnake.y += step * direction.y;
        element++;
        timer = 0;
    }
}
void Snake::draw()
{
    DrawRectangleV(positionSnake, sizeSnake, DARKGREEN);
    for (Vector2 x : bodyOld)
    {
        if (element <= 3)
        {
            DrawRectangleV(x, sizeSnake, DARKGREEN);
            std::cout << element << std::endl;
        }
        else
        {
           bodyOld.erase(bodyOld.begin());
           element--;
        }
    }
}