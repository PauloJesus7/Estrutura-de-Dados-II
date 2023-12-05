CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Arquivos fonte e objeto
SRCS = main.c utils.c
OBJS = $(SRCS:.c=.o)

# Nome do executável
TARGET = main

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC)  $(OBJS) -o $@

%.o: %.c
	$(CC) -c $< -o $@

clean:
	$(RM) $(TARGET) $(OBJS)

run: $(TARGET)
	./$(TARGET)

debug:
	make clean && make all && make run