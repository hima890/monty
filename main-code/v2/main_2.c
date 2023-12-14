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
	int checkArg = checkArguments(argc);
	int checkIntger, lineNumber = 0;
	char *fileBuffer = NULL;
	char *lineToken = NULL;
	char line[MAX_LINE_LENGTH];
	char *opcode, *argument;
	FILE *montyFile;
	stack_t *stack = NULL;

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
		char *nonWhiteSpace;
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

int isStringInteger(char *str)
{
	char *endptr;
	strtol(str, &endptr, 10);

	if (*endptr != '\0' && *endptr != '\n' && !isspace(*endptr))
	{
		return 0;
	}

	return 1;
}

/* Function to push a new element onto the stack */
void push(stack_t **stack, int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/* Function to free the memory allocated for the stack or queue */
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

int _isdigit(int c)
{
	int flag;
	if (c >= 48 && c <= 57)
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return (flag);
}

/* Function to print all values on the stack */
void pall_func(stack_t **stack)
{
	stack_t *current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

/* Function to print the value at the top of the stack */
void pint(stack_t **stack, unsigned int lineNumber)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/* Function to remove the top element from the stack */
void pop(stack_t **stack, unsigned int lineNumber)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/* Function to swap the top two elements of the stack */
void swap(stack_t **stack, unsigned int lineNumber)
{
	stack_t *first;
	stack_t *second;
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", lineNumber);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next = second->next;
	if (second->next != NULL)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;

	*stack = second;
}

/* Function to add the top two elements of the stack */
void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}

/* Function to do nothing (nop) */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	/* This function does nothing */
}
