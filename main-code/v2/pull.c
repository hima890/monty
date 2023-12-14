#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * pall_func - Prints all values on the stack.
 *
 * @stack: A pointer to the stack.
 *
 * Description:
 *   This function prints all the values on the stack. It takes
 *   the stack as a parameter and iterates through the stack,
 *   printing each element's value. If the stack is empty, it does
 *   nothing.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *
 * Example:
 *   pall_func(&stack);
 *   // Prints all values on the stack.
*/
void pall_func(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
