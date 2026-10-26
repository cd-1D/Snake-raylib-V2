#pragma once
#include "snake.hpp"
#include "apple.hpp"
class Game{
    private:
        Snake snake;
        Apple apple;
        int score = 0;
    public:
        void update();
        void draw();
};