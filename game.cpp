#include "game.hpp"
#include "iostream"
void Game::update()
{

    if (IsKeyPressed(KEY_SPACE) && state != pause)
    {
        state = pause;
    }
    else if (IsKeyPressed(KEY_SPACE) && state == pause)
    {
        state = play;
    }

    if (state == play)
    {
        // проверяем колизии с яблоком
        if (CheckCollisionRecs(apple.getRec(), snake.getRec()))
        {
            std::cout << "collision!" << std::endl;
            apple.update();
            score++;
        }
        // проверяем вышла ли змейка за границы экрана
        if (snake.getPosHead().x > 600 || snake.getPosHead().y > 600 || snake.getPosHead().x < 0 || snake.getPosHead().y < 0)
        {
            std::cout << "game_over!" << std::endl;
            state = game_over;
        }
        if (snake.checkCollision())
        {
            state = game_over;
        }
        snake.update(score);
    }
}
void Game::draw()
{
    snake.draw();
    apple.draw(apple.getPositionApple());
    if (state == play)
    {
        DrawText(TextFormat("score: %i", score), 20, 20, 25, WHITE);
    }
    if (state == game_over)
    {
        DrawText("Game over!", 240, 300, 25, RED);
        DrawText(TextFormat("score: %i", score), 260, 230, 25, GREEN);
    }
    if (state == pause)
    {
        DrawText(TextFormat("score: %i", score), 20, 20, 25, WHITE);
        DrawText("Press escape to continue...", 160, 230, 25, WHITE);
    }
}
