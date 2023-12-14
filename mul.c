#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * mul - Multiplication operation.
 *
 * @stack: A pointer to the stack.
 * @line_number: Line number in the file where the operation occurs.
 *
 * Description:
 *   Multiplies the top element of the stack with the second top element.
 *   If the stack contains fewer than two elements, prints an error
 *  message and exits.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - line_number: Line number in the file where the operation occurs.
 *
 * Example:
 *   mul(&stack, 23);
 *   // Multiplies the top element with the second top element in the stack.
*/
void mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
