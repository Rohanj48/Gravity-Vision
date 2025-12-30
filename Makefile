# Compiler
CXX = g++
CXXFLAGS = -Iinclude -std=c++17 -Wall -g

# Linker flags for raylib on Windows (MinGW)
LDFLAGS = -Llib -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = $(shell find src -name "*.cpp")
BUILD_DIR = build
TARGET = $(BUILD_DIR)/app.exe

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

# Run the program after building
run: all
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean run
