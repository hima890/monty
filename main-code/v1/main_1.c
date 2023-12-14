#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * main - Entry point for the test program.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: Always 0.
 */

int main(int argc, char const *argv[])
{
	int checkArg = checkArguments(argc);
	int lineNumber = 0;
	char *fileBuffer = NULL;
	char *lineToken = NULL;
	char line[MAX_LINE_LENGTH];
	char *opcode, *argument;
	FILE *montyFile;

	if (checkArg != 0)
	{
		exit(EXIT_FAILURE);
	}

	montyFile = openfiles(argv[1]);

	if (montyFile == NULL)
	{
		exit(EXIT_FAILURE);
	}

	while (fgets(line, MAX_LINE_LENGTH, montyFile) != NULL)
	{
		lineNumber++;
		if (line[0] == '\0')
		{
			continue;
		}

		lineToken = strtok(line, " ");
		if (lineToken == NULL)
		{
			fprintf(stderr, "Error: malloc failed\n");
			free(fileBuffer);
			fclose(montyFile);
			exit(EXIT_FAILURE);
		}
		line[strcspn(line, "\n")] = '\0';
		opcode = lineToken;
		argument = strtok(NULL, " ");

		if (opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown error1\n", lineNumber);
			exit(EXIT_FAILURE);
		}
		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
				exit(EXIT_FAILURE);
			}
			printf("%s\n", opcode);
			printf("%s\n", argument);
		}
		else
		{
			fprintf(stderr, "L%d: unknown error1\n", lineNumber);
			exit(EXIT_FAILURE);
		}
		/* else if (strcmp(opcode, "pop") == 0)
		{
			// Handle pop errors if needed
		} */
		lineToken = strtok(NULL, " ");
	}

	fclose(montyFile);
	free(fileBuffer);
	return (0);
}
