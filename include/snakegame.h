#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "snake.h"
#include "level.h"
#include "player.h"
#include "direction.h"

class SnakeGame {
public:
    SnakeGame(const std::string &levelFile, int startX, int startY);
    void initializeGame();
    void update(int startX, int startY);
    void render();
    void processEvents();
    bool isGameOver();

private:
    Snake snake;
    Level level;
    Player player;
    int lives;
    int score;
    int foodLeft;
    std::pair<int, int> foodPosition;
    std::pair<int, int> generateFoodPosition(); // Método para gerar posição da comida
};

#endif // SNAKEGAME_H
