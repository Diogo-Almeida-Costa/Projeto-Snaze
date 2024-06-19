#ifndef PLAYER_H
#define PLAYER_H

#include "snake.h"
#include "level.h"
#include "direction.h"
#include <vector>
#include <map>
#include <set>
#include <queue>

class Player {
public:
    Player();
    bool findSolution(const Snake& snake, const Level& level);
    Direction nextMove();

private:
    std::vector<Direction> solutionPath; 
    size_t currentStep; 

    std::set<std::pair<int, int>> visited; 
    std::map<std::pair<int, int>, std::pair<int, int>> cameFrom; 

    std::vector<Direction> reconstructPath(const std::pair<int, int>& start, const std::pair<int, int>& goal);
    bool isValidMove(const std::pair<int, int>& position, const Level& level);
    std::vector<std::pair<int, int>> getNeighbors(const std::pair<int, int>& position);

    bool bfs(const Snake& snake, const Level& level, int startX, int startY, Direction& result);
};

#endif // PLAYER_H
