CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lGL -lGLU -lglut
TARGET = line
SRC = line.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET)
