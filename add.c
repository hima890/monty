#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * add - Adds the top two elements of the stack.
 *
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty file where the operation was called.
 *
 * Description:
 *   Adds the values of the top two elements of the stack. The result is stored
 *   in the second element from the top, and the top element is removed.
 *   If the stack contains fewer than two elements, print an error message to
 *   standard error and exit with EXIT_FAILURE.
 *
 * Parameters:
 *   - stack: Double pointer to the head of the stack.
 *   - line_number: Line number in the Monty file where the operation was
 *  called.
 *
 * Return:
 *   No explicit return value. Exits with EXIT_FAILURE if the stack is too
 *  short.
 *
 * Example:
 *   Input stack (top to bottom): 3, 7, 10
 *   After add, the stack becomes: 3, 17
*/
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
