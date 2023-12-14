#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * pop - Removes the top element from the stack.
 *
 * @stack: A pointer to the stack.
 * @lineNumber: The line number being executed.
 *
 * Description:
 *   This function removes the top element from the stack. It takes
 *   the stack and line number as parameters, checks if the stack is
 *   empty, and removes the top element if the stack is not empty.
 *   If the stack is empty, it prints an error message to the standard
 *   error output and exits with a failure status.
 *
 * Example:
 *   pop(&stack, 42);
 *   // If the stack is not empty, removes the top element;
 *  otherwise, prints an error and exits.
*/
void pop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}
