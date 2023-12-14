#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * pint - Prints the value at the top of the stack.
 *
 * @stack: A pointer to the stack.
 * @lineNumber: The line number being executed.
 *
 * Description:
 *   This function prints the integer value at the top of the stack.
 *   It takes the stack and line number as parameters, checks if the stack
 *   is empty, and prints the value at the top if the stack is not empty.
 *   If the stack is empty, it prints an error message to the standard error
 *   output and exits with a failure status.
 *
 * Example:
 *   pint(&stack, 42);
 *   // If the stack is not empty, prints the top value; otherwise,
 *  prints an error and exits.
*/
void pint(stack_t **stack, unsigned int lineNumber)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}
