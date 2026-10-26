#include "snake.hpp"
#include "raylib.h"
#include <vector>
void Snake::update(int score)
{

    float DT = GetFrameTime();
    timer += DT;
    if (IsKeyPressed(KEY_D) && direction.x != -1)
        direction = {1, 0};
    if (IsKeyPressed(KEY_A) && direction.x != 1)
        direction = {-1, 0};
    if (IsKeyPressed(KEY_W) && direction.y != 1)
        direction = {0, -1};
    if (IsKeyPressed(KEY_S) && direction.y != -1)
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
Rectangle Snake::getRec()
{
    Rectangle recSnake = {positionSnake.x, positionSnake.y, sizeSnake.x, sizeSnake.y};
    return recSnake;
}
Vector2 Snake::getPosHead()
{
    return positionSnake;
}
bool Snake::checkCollision()
{
    // проверяем колизии головы змеи с ее же телом
    for (int i = 0; i < body.size() - 1; i++)
    {
        if (getPosHead().x == body[i].x && getPosHead().y == body[i].y)
        {
            snakeCollision = true;
        }
    }
    return snakeCollision;
}