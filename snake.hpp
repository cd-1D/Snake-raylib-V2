#pragma once
#include "raylib.h"
#include <vector>
class Snake
{
private:

    Vector2 positionSnake = {300, 300};
    Vector2 sizeSnake = {20, 20};
    Vector2 direction = {1, 0};
    std::vector<Vector2> body = {positionSnake};
    std::vector<Vector2> bodyOld;
    int step = 20;
    int element = 0;
    float coolDown = 0.6f;
    float timer = 0.0f;
public:
    void update();
    void draw();
};