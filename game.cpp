#include "game.hpp"
#include "iostream"
void Game::update()
{
    if (CheckCollisionRecs(apple.getRec(), snake.getRec()))
    {
        std::cout << "collision!" << std::endl;
        apple.update();
        score++;
    }
    snake.update(score);
}
void Game::draw()
{
    DrawText(TextFormat("score: %i", score), 20, 20, 25, WHITE);
    DrawText(TextFormat("x: %i", apple.getPositionApple().x) , 20, 50, 25, WHITE);
    DrawText(TextFormat("y: %i", apple.getPositionApple().y) , 20, 90, 25, WHITE);
    snake.draw();
    apple.draw(apple.getPositionApple());
}
