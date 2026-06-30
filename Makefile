CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = main

SRC = main_stack.c src/stack.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)
