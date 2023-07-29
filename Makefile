CC = gcc
CFLAGS = -Wall -Wextra -std=c17

# Name of the executable
TARGET = terminal-snake

# Source files
SRCS = main.c test.c map.c utils.c controls.c

# Object files directory
OBJ_DIR = compiled_files

# Object files
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET)

