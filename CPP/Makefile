# Makefile for STL Viewer with OpenGL

CXX = g++
CXXFLAGS = -Wall -O2
LDFLAGS = -lGL -lGLU -lglut
TARGET = stl_viewer
SRC = stl_viewer.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(TARGET)
