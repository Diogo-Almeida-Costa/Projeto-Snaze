#include "../include/snakegame.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: snaze <input_level_file>" << std::endl;
        return 1;
    }

    // Exemplo de inicialização com startX = 0 e startY = 0
    SnakeGame game(argv[1], 0, 0); 

    game.initializeGame();

    while (!game.isGameOver()) {
        game.processEvents();
        game.update(0, 0); // Aqui você pode passar os valores desejados para startX e startY
        game.render();
    }

    return 0;
}

