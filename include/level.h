#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

class Level {
public:
    Level(const std::string& filePath);
    bool loadLevel();
    const std::vector<std::string>& getGrid() const;
    int getWidth() const;   // Retorna a largura do grid (número de colunas)
    int getHeight() const;  // Retorna a altura do grid (número de linhas)

private:
    std::string filePath;
    std::vector<std::string> grid;
};

#endif // LEVEL_H

