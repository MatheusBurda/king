# Project Name
PROJECT := king

# Source, Objects and Binaries folder
SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Compiler
CC := g++

# Flags
CPPFLAGS := -Iinclude # -I folder_to_includes
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm -lsfml-graphics -lsfml-window -lsfml-system

.PHONY: all clean build

all: build $(PROJECT) run

$(PROJECT): $(OBJ)
	@ $(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@
	@ echo '============================ Finished building ============================'

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	@ mkdir -p $@

build:
	@ echo '=============== Started building project using g++ compiler ==============='
	@ $(RM) $(OBJ_DIR)/main.o

clean:
	@ $(RM) -r $(OBJ_DIR) $(PROJECT) $(BIN_DIR)

rebuild: clean all

run:
	./$(PROJECT)

-include $(OBJ:.o=.d)