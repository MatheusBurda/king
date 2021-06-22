# Name of the project
PROJECT_NAME=game

# .cpp Files
CPP_SOURCE=$(wildcard ./source/*.cpp)

# .h Files
H_SOURCE=$(wildcard ./source/*.h)

# Object Files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(CPP_SOURCE)))

# Compiler
CC=g++

# Flags for Compiler
CC_FLAGS=-c


# Linker Flags
LINKER_FLAGS=-Wwrite-strings


# Compilation and linking
all: objFolder $(PROJECT_NAME)

$(PROJECT_NAME):	$(OBJ)
				@ echo 'Bulding binary using G++ linker: $@'
				$(CC) -o $@ $^ $(LINKER_FLAGS)
				@ echo 'Finished buiding binary: $@'
				@ echo ' '

./objects/%.o: ./source/%.cpp ./source/%.h
				@ echo 'Building target using G++ compiler: $<'
				$(CC) -o $@ $< $(CC_FLAGS)
				@ echo ' '

./objects/main.o: ./source/main.cpp $(H_SOURCE)
		    @ echo 'Building target using G++ compiler: $<'
		    $(CC) -o $@ $< $(CC_FLAGS)
		    @ echo ' '

objFolder:
				@ mkdir -p objects

clean:
		    @ $(RM) ./objects/*.o $(PROJECT_NAME) *~
		    @ rmdir objects
