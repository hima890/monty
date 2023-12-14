#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256
/**
 * mod - Modulus operation.
 *
 * @stack: A pointer to the stack.
 * @line_number: Line number in the file where the operation occurs.
 *
 * Description:
 *   Computes the remainder of the division of the second top element
 *  by the top element.
 *   If the stack contains fewer than two elements or if the top
 *  element is zero,
 *   prints an error message and exits.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - line_number: Line number in the file where the operation occurs.
 *
 * Example:
 *   mod(&stack, 28);
 *   // Computes the remainder of the division in the stack.
*/
void mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	pop(stack, line_number);
}
