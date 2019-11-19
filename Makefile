OBJS = src/Main.cpp src/app/Game.cpp src/engine/Application.cpp src/engine/Scene.cpp src/sdlx/Sdlx.cpp src/sdlx/Window.cpp src/sdlx/Renderer.cpp src/sdlx/Surface.cpp src/sdlx/Texture.cpp

CC = g++

COMPILER_FLAGS = -std=c++17

INCLUDE_FLAGS = -I include -L lib

LINKER_FLAGS = -l SDL2 -l SDL2_image -l SDL2_ttf -l SDL2_mixer

OBJ_NAME = bin/tic_tac_toe

all : $(OBJS)
		$(CC) $(OBJS) $(COMPILER_FLAGS) $(INCLUDE_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
