CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

TARGET = main

SRC = main_doubly.c src/doubly_linked_list.c

$(TARGET): $(SRC)

	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:

	rm -f $(TARGET)
