SRC_DIR := src
INCLUDE_DIR := lib
OBJ_DIR := obj
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
CC = gcc
CFLAGS = -g -Wall
EXEC = main 

all: $(EXEC) archive

$(EXEC): $(OBJS)
	$(CC) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	$(CC) -c $< -o $@ -I$(INCLUDE_DIR) 

archive:
	tar cfJ archive.tar.xz $(SRC_DIR) $(INCLUDE_DIR) $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(EXEC) archive.tar.xz archive

run: $(EXEC)
	./$<

valgrind-check: main
	valgrind ./$<