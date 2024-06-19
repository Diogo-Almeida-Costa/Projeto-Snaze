#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "snake.h"
#include "level.h"
#include "player.h"

class SnakeGame {
public:
    SnakeGame(const std::string &levelFile, int startX, int startY);
    void initializeGame();
    void update();
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
};

#endif // SNAKEGAME_H
