#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
 * my_strdup - Duplicate a string.
 *
 * @original: The original string to be duplicated.
 *
 * Return:
 * - On success, returns a pointer to the duplicated string.
 * - On failure or if the original string is NULL, returns NULL.
 *
 * Description:
 * - This function allocates memory for a new string and copies the content
 *   of the original string to the newly allocated memory.
 * - The returned string is null-terminated.
 * - It's the responsibility of the caller to free the allocated memory.
 */
char *my_strdup(const char *original)
{
	size_t length;
	char *duplicate;

	if (original == NULL)
	{
		return (NULL);
	}

	length = strlen(original) + 1;
	duplicate = malloc(length);

	if (duplicate != NULL)
	{
		strncpy(duplicate, original, length);
		duplicate[length - 1] = '\0';
	}

	return (duplicate);
}

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
	int i, j, count;
	char **duplicate;

	if (array == NULL)
		return (NULL);

	count = 0;
	while (array[count] != NULL)
		count++;

	duplicate = malloc((count + 1) * sizeof(char *));
	if (duplicate == NULL)
	{
		perror("Error: Memory allocation failed.");
		return (NULL);
	}

	for (i = 0; i < count; i++)
	{
		duplicate[i] = my_strdup(array[i]);
		if (duplicate[i] == NULL)
		{
			perror("Error: Memory allocation failed.");
			for (j = 0; j < i; j++)
				free(duplicate[j]);
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
	int i;

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
	for (i = 0; instructions[i] != NULL; i++)
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
	int i;

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
	for (i = 0; instructions[i] != NULL; i++)
	{
		free(instructions[i]);
	}

	free(instructions);
}
