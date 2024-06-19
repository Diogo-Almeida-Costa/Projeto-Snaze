# Nome do executável
TARGET = snaze
# Nome do compilador
CXX = g++

# Opções do compilador
CXXFLAGS = -Wall -std=c++17 -Iinclude

# Diretórios
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin
INC_DIR = include

# Arquivos fonte e objeto
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Nome do executável
TARGET = $(BIN_DIR)/snakegame

# Regras de construção
all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all clean
