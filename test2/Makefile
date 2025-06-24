# Makefile for hilbert_opengl2.cpp using GLFW + GLEW + OpenGL 2

CXX      := g++
SRC      := hilbert_opengl2.cpp
OBJ      := $(SRC:.cpp=.o)
BIN      := hilbert

# Use pkg-config for compile & link flags
PKG      := $(shell pkg-config --cflags --libs glfw3 glew)
GL       := -lGL
CXXFLAGS := -Wall -Wextra -O2

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(OBJ) -o $(BIN) $(PKG) $(GL)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(PKG) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJ) $(BIN)
