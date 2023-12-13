#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


/**
 * tokenizeInput - a line buffer into instructions.
 * This function takes a line buffer and tokenizes it into instructions
 * , removing any empty tokens. It returns an array of pointers to the
 *  instructions, with the array null-terminated. It ensures that the
 *  returned array is not affected by future modifications.
 *
 * @lineBuffer: A pointer to the line buffer to be tokenized.
 *
 * Return:
 *	A dynamically allocated array of pointers to instructions, null-terminated.
 *	Returns NULL on error, such as an invalid line buffer pointer or if memory
 *  allocation fails. The caller is responsible for freeing the returned array
 *         when it is no longer needed.
 *
 * Note: The caller need to free the return list
*/
char **tokenizeInput(char *lineBuffer)
{
	/* Check for line buffer not null */
	if (lineBuffer == NULL)
	{
		/* Print error message to the stander error output*/
		fprintf(stderr, "Error: Invalid line buffer pointer.\n");
		/* Return Null */
		return (NULL);
	}
	/* Token return a C string */
	char *token = strtok(lineBuffer, " ");
	/* Declare with enough space for 2 instructions + null terminator */
	char *lineInstructions[4];
	/* Int the counter */
	int i = 0;

	/* Ensure not to exceed the array size */
	while (token != NULL && i < 3)
	{
		/* Check for the empty token C string */
		if (strcmp(token, "") == 0)
		{
			/* Pass the empty string in the loop */
			continue;
		}
		else
		{
			/* If not empty token C string add it to the line instructions */
			lineInstructions[i] = strdup(token);
			/* Incruse the counter */
			i++;
		}
		/* Get the next token C string */
		token = strtok(NULL, " ");
	}
	/* Null-terminate the argument array */
	lineInstructions[i] = NULL;
	/* Return a duplicate to ensure it's not affected by future modifications */
	return (duplicateStringArray(lineInstructions));
}
