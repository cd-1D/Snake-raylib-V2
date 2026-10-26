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
    int step = 20;
    int element = 0;
    float coolDown = 0.2f;
    float timer = 0.0f;
    bool snakeCollision = false;
public:
    void update(int score);
    void draw();
    bool checkCollision();
    Rectangle getRec();
    Vector2 getPosHead();
};