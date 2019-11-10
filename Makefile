OBJS = src/Main.cpp src/game/Game.cpp src/game/Grid.cpp src/game/GridSlot.cpp src/game/Chip.cpp src/game/Player.cpp src/util/StringUtil.cpp

CC = g++

COMPILER_FLAGS = -std=c++17

OBJ_NAME = bin/tic_tac_toe

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) -o $(OBJ_NAME)
