#ifndef SNAKE_H
#define SNAKE_H

#include <deque>
#include <utility>
#include "direction.h"

class Snake {
public:
    Snake(int startX, int startY);
    void move(Direction dir);
    void grow();
    bool isCollision(int x, int y);
    const std::deque<std::pair<int, int>>& getBody() const;

private:
    std::deque<std::pair<int, int>> body;
    //int direction;
    Direction currentDirection;
};

#endif // SNAKE_H
