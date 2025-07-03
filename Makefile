CC = gcc
CFLAGS = -Wall -Iinclude
SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
TARGET = main

all: $(TARGET)

$(TARGET): main.c $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ 

clean:
	rm -f $(TARGET) src/*.o
