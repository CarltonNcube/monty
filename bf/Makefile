CC = gcc

CFLAGS = -Wall -Werror -Wextra -pedantic -std=c89

SRCS = monty.c opcode_execution.c instruction_parser.c stack_operations.c main_helpers.c

OBJS = $(SRCS:.c=.o)

TARGET = monty

all: $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS)

distclean: clean
	rm -f $(TARGET)
