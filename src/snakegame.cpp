#include "../include/snakegame.h"
#include <iostream>
#include <ctime>
#include <string>

SnakeGame::SnakeGame(const std::string &levelFile, int startX, int startY)
    : snake(startX, startY), level(levelFile), lives(5), score(0), foodLeft(10) {

    std::srand(std::time(nullptr)); // Inicializa a semente para geração de números aleatórios
    generateFoodPosition(); // Inicializa a posição da comida
}


void SnakeGame::initializeGame() {
    if (!level.loadLevel()) {
        std::cerr << "Failed to load level" << std::endl;
        exit(1);
    }

    // Obter o grid do nível carregado
    const std::vector<std::string>& grid = level.getGrid();

    // Definir a posição inicial da cobra
    // Aqui, por exemplo, você pode escolher uma posição inicial fixa ou aleatória
    int startX = 5;  // Exemplo de posição inicial X
    int startY = 5;  // Exemplo de posição inicial Y

    // Inicializar a cobra com a posição inicial obtida
    snake = Snake(startX, startY);
}

std::pair<int, int> SnakeGame::generateFoodPosition() {
    const auto& grid = level.getGrid();
    std::pair<int, int> newPosition;

    do {
        // Gerar uma posição aleatória dentro dos limites do nível
        newPosition.first = rand() % grid[0].size();
        newPosition.second = rand() % grid.size();
    } while (snake.isCollision(newPosition.first, newPosition.second));

    return newPosition;
}


void SnakeGame::update(int startX, int startY) {
    snake = Snake(startX, startY);
        // Atualizar o estado do jogo
    std::pair<int, int> head = snake.getBody().front();
    if (head == foodPosition) {
        snake.grow();  // Crescer a cobra
        score += 10;   // Aumentar a pontuação
        foodLeft--;    // Decrementar o número de comidas restantes
        foodPosition = generateFoodPosition();  // Gerar nova posição para a comida
    }
    // Recriar a cobra na posição inicial
    if (head.first < 0 || head.first >= level.getGrid()[0].size() ||
        head.second < 0 || head.second >= level.getGrid().size() ||
        snake.isCollision(head.first, head.second)) {
        // A cobra colidiu, decrementar vidas
        lives--;
        // Reiniciar a posição da cobra
        snake = Snake(startX, startY);
    }
}

void SnakeGame::render() {
    // Limpar a tela ou renderizar sobre a tela existente, dependendo do ambiente gráfico
    std::system("clear"); // Limpa a tela no terminal Unix-like, use "cls" no Windows se estiver usando

    // Obter o grid do nível
    const auto& grid = level.getGrid();

    // Renderizar o nível
    for (const auto& row : grid) {
        std::cout << row << std::endl;
    }

    // Obter o corpo da cobra
    const auto& body = snake.getBody();

    // Renderizar a cobra
    for (const auto& segment : body) {
        // Aqui, dependendo da implementação do grid, você pode usar um caractere para representar a cobra
        // Por exemplo, usando 'O' para a cabeça e 'o' para o corpo, se o grid permitir isso
        std::cout << "Cobra: (" << segment.first << ", " << segment.second << ")" << std::endl;
    }

    // Renderizar outras informações como vidas, pontuação, etc.
    std::cout << "Vidas: " << lives << std::endl;
    std::cout << "Pontuação: " << score << std::endl;
    std::cout << "Comidas restantes: " << foodLeft << std::endl;

    // Pausa para visualização (opcional, dependendo da velocidade do loop de jogo)
    // std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Exemplo de pausa de 100ms
}

// No lugar de _kbhit(), simula-se a entrada de dados pelo teclado com std::cin
bool kbhit() {
    return std::cin.peek() != EOF; // Verifica se há entrada disponível
}

// No lugar de _getch(), simula-se a captura da tecla com std::cin
char getch() {
    char key;
    std::cin >> std::noskipws >> key; // Captura a tecla pressionada
    return key;
}

// Função principal que processa os eventos de teclado
void SnakeGame::processEvents() {
    if (kbhit()) { // Verifica se há uma tecla pressionada no Windows usando conio.h
        char key = getch(); // Obtém a tecla pressionada

        switch (key) {
            case 'w':
                snake.move(Direction::UP);
                break;
            case 's':
                snake.move(Direction::DOWN);
                break;
            case 'a':
                snake.move(Direction::LEFT);
                break;
            case 'd':
                snake.move(Direction::RIGHT);
                break;
            case 'q':
                lives = 0; // Simula pressionamento de 'q' para sair do jogo
                break;
            default:
                break;
        }
    }
}



bool SnakeGame::isGameOver() {
    // Verificar se o jogo acabou
    return lives <= 0;
}
