#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

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
	char *fileBuffer = NULL;
	char *lineToken = NULL;
	char **tokenizeArg = NULL;
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

	fileBuffer = readFiles(montyFile);

	if (fileBuffer == NULL)
	{
		fclose(montyFile);
		exit(EXIT_FAILURE);
	}

	lineToken = strtok(fileBuffer, "\n");

	while (lineToken != NULL)
	{
		int i;

		tokenizeArg = tokenizeInput(lineToken);

		if (tokenizeArg == NULL) {
			fprintf(stderr, "Error: malloc failed\n");
			free(fileBuffer);
			fclose(montyFile);
			exit(EXIT_FAILURE);
		}

		for (i = 0; tokenizeArg[i] != NULL; i++)
		{
			printf("  %s\n", tokenizeArg[i]);
			free(tokenizeArg[i]);
		}

		free(tokenizeArg);
		lineToken = strtok(NULL, "\n");
	}

	free(fileBuffer);
	return (0);
}
