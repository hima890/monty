#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * main - Entry point for the test program.
 *
 * Return: Always 0.
*/
int main(void)
{
	/* Test Case 1: Valid input with multiple instructions */
	char input1[] = "push 0\n";
	char **result1 = tokenizeInput(input1);

	printf("Test Case 1 Result:\n");
	printInstructions(result1);
	freeInstructions(result1);

	/* Test Case 2: Valid input with leading and trailing spaces */
	char input2[] = "    push 5      \n";
	char **result2 = tokenizeInput(input2);

	printf("\nTest Case 2 Result:\n");
	printInstructions(result2);
	freeInstructions(result2);

	/* Test Case 3: Empty input */
	char input3[] = "\n";
	char **result3 = tokenizeInput(input3);

	printf("\nTest Case 3 Result:\n");
	printInstructions(result3);
	freeInstructions(result3);

	/* Test Case 4: Invalid input (NULL pointer) */
	char **result4 = tokenizeInput(NULL);

	printf("\nTest Case 4 Result:\n");
	if (result4 == NULL)
	{
		printf("Error: Invalid line buffer pointer.\n");
	}

	return (0);
}
