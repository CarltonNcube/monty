#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

void push(stack_t **stack, int value);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void parse_instruction(char *line, char **opcode, char **arg);
void execute_instruction(char *opcode, stack_t **stack, unsigned int line_number);
void main_loop(FILE *file);
int main(int argc, char *argv[])
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct
{
    char *opcode;
    void (*func)(stack_t **, unsigned int);
} opcode_func_pair;

opcode_func_pair opcode_functions[] = {
    {"push", push},
    {"pall", pall},
    {"pint", pint},
    {"pop", pop},
    {"swap", swap}
};

#endif /* MONTY_H */

