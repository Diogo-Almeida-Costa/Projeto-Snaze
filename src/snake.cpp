#include "../include/snake.h"
#include "../include/direction.h"

Snake::Snake(int startX, int startY) {
    body.push_back({startX, startY});
    currentDirection = Direction::RIGHT;  // Começa movendo para a direita
}

void Snake::move(Direction dir) {
    // Atualiza a direção atual da cobra
    currentDirection = dir;

    // Move a cabeça da cobra para a nova posição de acordo com a direção
    std::pair<int, int> head = body.front();
    int newX = head.first;
    int newY = head.second;

    switch (dir) {
        case Direction::UP:
            --newY;
            break;
        case Direction::DOWN:
            ++newY;
            break;
        case Direction::LEFT:
            --newX;
            break;
        case Direction::RIGHT:
            ++newX;
            break;
        default:
            break;
    }

    // Adiciona a nova posição da cabeça à frente da deque
    body.push_front({newX, newY});
}

void Snake::grow() {
    // Obter a posição da cauda atual
    std::pair<int, int> tail = body.back();

    // Determinar a nova posição para o novo segmento da cauda
    // Aqui, uma implementação simples adiciona um novo segmento na direção oposta à cabeça
    int tailX = tail.first;
    int tailY = tail.second;

    // Determinar a direção oposta à direção atual da cabeça
    Direction oppositeDirection;
    switch (currentDirection) {
        case Direction::UP:
            tailY++;
            break;
        case Direction::DOWN:
            tailY--;
            break;
        case Direction::LEFT:
            tailX++;
            break;
        case Direction::RIGHT:
            tailX--;
            break;
        default:
            break;
    }

    // Adicionar o novo segmento à cauda da cobra
    body.push_back({tailX, tailY});
}


bool Snake::isCollision(int x, int y) {
    // Verifica se a posição (x, y) está na cobra (ignora a cabeça)
    for (auto it = body.begin() + 1; it != body.end(); ++it) {
        if (it->first == x && it->second == y) {
            return true;
        }
    }
    return false;
}

const std::deque<std::pair<int, int>>& Snake::getBody() const {
    return body;
}

