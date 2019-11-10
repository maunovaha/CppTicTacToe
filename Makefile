OBJS = src/Main.cpp src/Game.cpp src/Gameboard.cpp src/GridSlot.cpp src/StringFormatter.cpp

CC = g++

COMPILER_FLAGS = -std=c++17

OBJ_NAME = bin/tic_tac_toe

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
