#include "../include/snake.h"

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    direction = 0; // ou qualquer direção padrão
}

void Snake::move(Direction dir) {
    // Implementar a lógica de movimento
}

void Snake::grow() {
    // Implementar a lógica de crescimento
}

bool Snake::isCollision(int x, int y) {
    // Implementar a lógica de colisão
}

const std::deque<std::pair<int, int>>& Snake::getBody() const {
    return body;
}
