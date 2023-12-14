#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdio.h>

/* Structions */
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototype */
int checkArguments(int argc);
char **tokenizeInput(char *lineBuffer);
char **duplicateStringArray(char **array);
void printInstructions(char **instructions);
void freeInstructions(char **instructions);
FILE *openfiles(const char *filePath);
char *my_strdup(const char *original);
int isStringInteger(char *str);
void push(stack_t **stack, int n);
void pall_func(stack_t **stack);
void free_stack(stack_t **stack);
void pint(stack_t **stack, unsigned int lineNumber);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int lineNumber);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void ex2(char *opcode, char *argument, stack_t *stack, int lineNumber);

#endif