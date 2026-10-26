#pragma once
#include "raylib.h"
class Snake
{
private:
    Vector2 positionSnake = {300, 300};
    Vector2 sizeSnake = {20, 20};
    Vector2 direction = {1, 0};
    int speed = 20;
    float coolDown = 0.8f;
    float timer = 0.0f;
public:
    void update();
    void draw();
};