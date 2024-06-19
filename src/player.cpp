#include "../include/player.h"
#include "../include/direction.h"

Player::Player() {
    // Construtor vazio
}

bool Player::findSolution(const Snake& snake, const Level& level) {
    Direction result = Direction::NONE;
    
    // Obtém a posição atual da cabeça da cobra
    const auto& body = snake.getBody();
    int startX = body.front().first;
    int startY = body.front().second;

    // Chamada para o BFS para encontrar uma solução
    bool found = bfs(snake, level, startX, startY, result);
    return found;
}

Direction Player::nextMove() {
    // Implementar lógica de próximo movimento
    return UP;
}
