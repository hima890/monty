#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256
/**
 * pstr - Print string operation.
 *
 * @stack: A pointer to the stack.
 * @line_number: Line number in the file where the operation occurs.
 *
 * Description:
 *   Prints the ASCII string starting from the top of the stack until
 *  a zero value is encountered,
 *   or until the value is out of the ASCII range (0-127). If the
 *  stack is empty,
 *   prints a newline character.
 *
 * Parameters:
 *   - stack: A pointer to the stack.
 *   - line_number: Line number in the file where the operation occurs.
 *
 * Example:
 *   pstr(&stack, 45);
 *   // Prints the ASCII string starting from the top of the stack.
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *cu = *stack;

	(void)line_number;
	while (cu != NULL && cu->n != 0 && (cu->n >= 0 && cu->n <= 127))
	{
		putchar(cu->n);
		cu = cu->next;
	}

	putchar('\n');
}
