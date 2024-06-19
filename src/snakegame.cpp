#include "../include/snakegame.h"
#include <iostream>

SnakeGame::SnakeGame(const std::string &levelFile, int startX, int startY)
    : snake(startX, startY), level(levelFile), lives(5), score(0), foodLeft(10) {
    // Inicializações adicionais...
}

void SnakeGame::initializeGame() {
    if (!level.loadLevel()) {
        std::cerr << "Failed to load level" << std::endl;
        exit(1);
    }
    // Inicializar a posição da cobra
}

void SnakeGame::update() {
    // Atualizar o estado do jogo
}

void SnakeGame::render() {
    // Renderizar o estado do jogo
}

void SnakeGame::processEvents() {
    // Processar eventos do jogo
}

bool SnakeGame::isGameOver() {
    // Verificar se o jogo acabou
    return lives <= 0;
}
