#include "snake.hpp"
#include "raylib.h"
#include "config.hpp"
#include <iostream>
#include <vector>
void Snake::update(int score)
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
        body.push_back(positionSnake);
        positionSnake.x += step * direction.x;
        positionSnake.y += step * direction.y;
        element++;
        timer = 0;
        if (element >= 3 + score)
        {
            body.erase(body.begin());
            element--;
        }
    }
}
void Snake::draw()
{
    for (Vector2 x : body)
    {
        DrawRectangleV(x, sizeSnake, DARKGREEN);
    }
}
Rectangle Snake::getRec(){
    Rectangle recSnake = {positionSnake.x , positionSnake.y, sizeSnake.x, sizeSnake.y};
    return recSnake;
}