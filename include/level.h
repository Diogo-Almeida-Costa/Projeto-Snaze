#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

class Level {
public:
    Level(const std::string& filePath);
    bool loadLevel();
    const std::vector<std::string>& getGrid() const;

private:
    std::string filePath;
    std::vector<std::string> grid;
};

#endif // LEVEL_H
