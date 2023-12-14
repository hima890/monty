#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * push - Pushes a new element onto the stack.
 *
 * @stack: A pointer to the stack.
 * @n: The value to be pushed onto the stack.
 *
 * Description:
 *   This function creates a new node with the given value 'n' and
 *   pushes it onto the top of the stack. If the allocation fails,
 *   it prints an error message and exits with a failure status.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - n: The value to be pushed onto the stack.
 *
 * Example:
 *   push(&stack, 42);
 *   // Pushes the value 42 onto the stack.
*/
void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}
