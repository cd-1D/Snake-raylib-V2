#pragma once
#include "snake.hpp"
#include "apple.hpp"
class Game
{
private:
    enum State
    {
        pause,
        game_over,
        play
    };
    State state = play; 
    Snake snake;
    Apple apple;
    int score = 0;

public:
    void update();
    void draw();
};