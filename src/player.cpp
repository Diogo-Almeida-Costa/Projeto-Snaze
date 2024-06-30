#include "../include/player.h"
#include "../include/direction.h"
#include "../include/level.h"
#include <queue>
#include <vector>

Player::Player() {
    // Construtor vazio
}

bool Player::bfs(const Snake& snake, const Level& level, int startX, int startY, Direction& resultDirection) {
    const std::vector<std::string>& grid = level.getGrid(); // Obtém o grid do level

    // Verifica se a posição inicial está dentro dos limites
    if (startX < 0 || startY < 0 || startX >= grid[0].size() || startY >= grid.size())
        return false;

    // Movimentos possíveis (UP, DOWN, LEFT, RIGHT)
    std::vector<Direction> directions = { Direction::UP, Direction::DOWN, Direction::LEFT, Direction::RIGHT };

    // Fila para o BFS
    std::queue<std::pair<int, int>> q;
    q.push({ startX, startY });

    // Mapa de visitados
    std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
    visited[startY][startX] = true;

    // Mapa para armazenar os pais dos nós para reconstruir o caminho
    std::vector<std::vector<std::pair<int, int>>> parent(grid.size(), std::vector<std::pair<int, int>>(grid[0].size(), {-1, -1}));

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // Chegamos ao destino
        if (grid[y][x] == 'F') {
            // Reconstrói o caminho até o ponto inicial
            while (parent[y][x] != std::make_pair(startX, startY)) {
                std::pair<int, int> prev = parent[y][x];
                x = prev.first;
                y = prev.second;
            }

            // Determina a direção baseada no próximo movimento
            if (x == startX - 1) resultDirection = Direction::LEFT;
            else if (x == startX + 1) resultDirection = Direction::RIGHT;
            else if (y == startY - 1) resultDirection = Direction::UP;
            else if (y == startY + 1) resultDirection = Direction::DOWN;

            return true;
        }

        // Tenta mover-se para cada direção
        for (auto dir : directions) {
            int nx = x, ny = y;
            switch (dir) {
                case Direction::UP: ny--; break;
                case Direction::DOWN: ny++; break;
                case Direction::LEFT: nx--; break;
                case Direction::RIGHT: nx++; break;
            }

            // Verifica se a próxima posição é válida e não visitada
            if (nx >= 0 && ny >= 0 && nx < grid[0].size() && ny < grid.size() &&
                !visited[ny][nx] && (grid[ny][nx] == ' ' || grid[ny][nx] == 'F')) {
                q.push({ nx, ny });
                visited[ny][nx] = true;
                parent[ny][nx] = { x, y };
            }
        }
    }

    return false; // Se não encontrou um caminho válido
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
    if (solutionPath.empty()) {
        return Direction::NONE;  // Se não houver caminho, não há movimento possível
    }

    // Obter a próxima direção do caminho
    Direction nextDirection = static_cast<Direction>(solutionPath[currentStep]);
    
    // Atualizar o índice para a próxima direção no próximo movimento
    ++currentStep;

    return nextDirection;
}

