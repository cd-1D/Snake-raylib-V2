#pragma once
#include "snake.hpp"
class Game{
    private:
        Snake snake;
    public:
        void update();
        void draw();
};