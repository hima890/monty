#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
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
	int checkIntger, lineNumber = 0;
	char *nonWhiteSpace, *opcode, *argument, line[MAX_LINE_LENGTH];
	char *lineToken, *fileBuffer = NULL;
	FILE *montyFile;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
		nonWhiteSpace = line;
		while (*nonWhiteSpace != '\0' && isspace(*nonWhiteSpace))
		{
			nonWhiteSpace++;
		}
		if (*nonWhiteSpace == '\0')
		{
			continue;
		}
		lineToken = strtok(nonWhiteSpace, " ");
		if (lineToken == NULL)
		{
			fprintf(stderr, "Error: empty line at L%d\n", lineNumber);
			exit(EXIT_FAILURE);
		}
		line[strcspn(line, "\n")] = '\0';
		opcode = lineToken;
		argument = strtok(NULL, " ");
		if (strcmp(opcode, "push") == 0)
		{
			if (argument == NULL || *argument == '\0')
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
				exit(EXIT_FAILURE);
			}
			checkIntger = isStringInteger(argument);
			if (checkIntger == 0)
			{
				fprintf(stderr, "L%d: usage: push integer\n", lineNumber);
				exit(EXIT_FAILURE);
			}
			push(&stack, atoi(argument));
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall_func(&stack);
		}
		else if (strcmp(opcode, "pint") == 0)
		{
			pint(&stack, lineNumber);
		}
		else if (strcmp(opcode, "pop") == 0)
		{
			pop(&stack, lineNumber);
		}
		else if (strcmp(opcode, "swap") == 0)
		{
			swap(&stack, lineNumber);
		}
		else if (strcmp(opcode, "add") == 0)
		{
			add(&stack, lineNumber);
		}
		else if (strcmp(opcode, "nop") == 0)
		{
			nop(&stack, lineNumber);
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", lineNumber, opcode);
			exit(EXIT_FAILURE);
		}
	}

	fclose(montyFile);
	free(fileBuffer);
	/* Free memory */
	free_stack(&stack);
	return (0);
}
