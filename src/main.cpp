#include "../include/snakegame.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: snaze <input_level_file>" << std::endl;
        return 1;
    }

    SnakeGame game(argv[1]);
    game.initializeGame();

    while (!game.isGameOver()) {
        game.processEvents();
        game.update();
        game.render();
    }

    return 0;
}
