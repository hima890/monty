#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * free_stack - Frees the memory allocated for the stack or queue.
 *
 * @stack: Double pointer to the head of the stack or queue.
 *
 * Description:
 *   Frees the memory allocated for each node in the stack or queue.
 *   It iterates through the linked list, starting from the head, and frees
 *   each node until the end is reached.
 *   After calling this function, the stack or queue pointer is set to NULL.
 *
 * Parameters:
 *   - stack: Double pointer to the head of the stack or queue.
 *
 * Return:
 *   No explicit return value. The stack or queue pointer is set to NULL.
 *
 * Example:
 *   Input stack (top to bottom): 3, 7, 10
 *   After free_stack, the stack becomes: (empty)
*/
void free_stack(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
