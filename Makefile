CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = main

SRC = main.c src/dynamic_array.c

$(TARGET): $(SRC)

	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:

	rm -f $(TARGET)
