#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * duplicateStringArray - Duplicate an array of strings.
 * @array: The array of strings to be duplicated.
 *
 * This function duplicates an array of strings, returning a new array.
 *
 * Return: A dynamically allocated array of duplicated strings.
 */
char **duplicateStringArray(char **array)
{
	if (array == NULL)
	{
		return (NULL);
	}

	int count = 0;

	while (array[count] != NULL)
	{
		count++;
	}

	char **duplicate = malloc((count + 1) * sizeof(char *));

	if (duplicate == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		return (NULL);
	}

	for (int i = 0; i < count; i++)
	{
		duplicate[i] = strdup(array[i]);
		if (duplicate[i] == NULL)
		{
			fprintf(stderr, "Error: Memory allocation failed.\n");
			free(duplicate);
			return (NULL);
		}
	}

	duplicate[count] = NULL;

	return (duplicate);
}

/**
 * printInstructions - Print an array of instructions.
 * @instructions: The array of instruction strings.
 *
 * This function prints each instruction in the given array on a new line.
 *
 * @instructions: The array of instruction strings.
 *
 * Return: void
 */
void printInstructions(char **instructions)
{
	if (instructions == NULL)
	{
		/**
		 * If the instructions pointer is NULL, print an error message
		 * and return from the function.
		 */
		printf("Error: Invalid instructions pointer.\n");
		return;
	}

	/**
	 * Loop through the array of instruction strings and print each
	 * instruction on a new line.
	 */
	printf("Instructions:\n");
	for (int i = 0; instructions[i] != NULL; i++)
	{
		printf("  %s\n", instructions[i]);
	}
}

/**
 * freeInstructions - Free memory allocated for an array of instructions.
 * @instructions: The array of instruction strings.
 *
 * This function frees the memory allocated for each instruction string
 * in the array and then frees the array itself.
 *
 * @instructions: The array of instruction strings.
 *
 * Return: void
 */
void freeInstructions(char **instructions)
{
	if (instructions == NULL)
	{
		/**
		 * If the instructions pointer is NULL, print an error message
		 * and return from the function.
		 */
		printf("Error: Invalid instructions pointer.\n");
		return;
	}

	/**
	 * Loop through the array of instruction strings, free the memory
	 * allocated for each instruction, and then free the array itself.
	 */
	for (int i = 0; instructions[i] != NULL; i++)
	{
		free(instructions[i]);
	}

	free(instructions);
}
