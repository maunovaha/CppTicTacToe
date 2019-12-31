INCLUDE_DIR  := include
LIBRARY_DIR  := lib
SOURCE_DIR   := src
BUILD_DIR    := build
TARGET_DIR   := bin

CXX          := g++
CXX_SOURCES  := $(shell find $(SOURCE_DIR) -type f -name '*.cpp')
CXX_OBJECTS  := $(patsubst $(SOURCE_DIR)/%,$(BUILD_DIR)/%,$(CXX_SOURCES:.cpp=.o))
CXX_FLAGS    := -ggdb -std=c++17 -Wall

LIBRARIES    := SDL2 SDL2_image SDL2_ttf SDL2_mixer
LINKER_FLAGS := $(foreach library,$(LIBRARIES),-l$(library))
INCLUDE      := -I $(INCLUDE_DIR)

EXECUTABLE   := CppTicTacToe
TARGET       := $(TARGET_DIR)/$(EXECUTABLE)

main: $(CXX_OBJECTS)
	@echo "*** Linking ***"
	@mkdir -p $(TARGET_DIR)
	$(CXX) $^ -o $(TARGET) $(LINKER_FLAGS)

$(BUILD_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	@echo "*** Building ***"
	@mkdir -p $(BUILD_DIR)/engine/core/sdl
	@mkdir -p $(BUILD_DIR)/engine/io
	@mkdir -p $(BUILD_DIR)/engine/math
	@mkdir -p $(BUILD_DIR)/engine/scene
	@mkdir -p $(BUILD_DIR)/engine/ui
	@mkdir -p $(BUILD_DIR)/engine/world
	@mkdir -p $(BUILD_DIR)/game/mainmenu
	@mkdir -p $(BUILD_DIR)/game/gameplay
	@mkdir -p $(BUILD_DIR)/game/gameover
	@mkdir -p $(BUILD_DIR)/game/shared
	$(CXX) $(CXX_FLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@echo "*** Cleaning ***"
	$(RM) -r $(BUILD_DIR) $(TARGET)

.PHONY: clean