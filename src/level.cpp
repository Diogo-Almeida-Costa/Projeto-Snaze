#include "../include/level.h"
#include <fstream>
#include <sstream>

Level::Level(const std::string& filePath) : filePath(filePath) {}

bool Level::loadLevel() {
    std::ifstream file(filePath);
    if (!file.is_open()) return false;

    std::string line;
    while (std::getline(file, line)) {
        grid.push_back(line);
    }

    file.close();
    return true;
}

const std::vector<std::string>& Level::getGrid() const {
    return grid;
}

int Level::getWidth() const {
    if (grid.empty()) return 0;
    return grid[0].size();
}

int Level::getHeight() const {
    return grid.size();
}