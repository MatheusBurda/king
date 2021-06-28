# Project Name
PROJECT := sistemaAcademico

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
LDLIBS   := -lm

.PHONY: all clean build

all: build $(PROJECT)

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

-include $(OBJ:.o=.d)