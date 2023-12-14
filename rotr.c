#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * rotr - Rotate right operation.
 *
 * @stack: A pointer to the stack.
 * @line_number: Line number in the file where the operation occurs.
 *
 * Description:
 *   Rotates the stack to the bottom. The last element becomes the top,
 *   and the second last element becomes the new second top. If the stack
 *   contains fewer than two elements, no change is made.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - line_number: Line number in the file where the operation occurs.
 *
 * Example:
 *   rotr(&stack, 53);
 *   // Rotates the stack to the bottom.
*/
void rotr(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		stack_t *temp = *stack;
		stack_t *current;

		*stack = (*stack)->next;

		temp->next = NULL;
		temp->prev = NULL;

		current = *stack;

		while (current->next != NULL)
			current = current->next;

		current->next = temp;
		temp->prev = current;
	}
}
