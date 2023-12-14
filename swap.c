#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @stack: A pointer to the stack.
 * @lineNumber: The line number in the file where the operation occurred.
 *
 * Description:
 *   This function swaps the top two elements of the stack. If the stack
 *   is too short (less than two elements), it prints an error message and
 *   exits with a failure status.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - lineNumber: The line number in the file where the operation occurred.
 *
 * Example:
 *   swap(&stack, 5);
 *   // Swaps the top two elements of the stack.
*/
void swap(stack_t **stack, unsigned int lineNumber)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}
