#include <stdio.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point of the program, contains test
 *  cases for openThefiles function.
 *
 * Return: Always 0.
*/
int main(void)
{
	/* Test Case 1: Valid file path */
	char *validFilePath = "test.txt";
	FILE *file1 = openThefiles(validFilePath);

	if (file1 != NULL)
	{
		printf("Test Case 1: File opened successfully.\n");
		fclose(file1);
	}
	else
	{
		printf("Test Case 1: Failed to open the file.\n");
	}

	/* Test Case 2: Invalid file path */
	char *invalidFilePath = "nonexistent.txt";
	FILE *file2 = openThefiles(invalidFilePath);

	if (file2 != NULL)
	{
		printf("Test Case 2: File opened successfully.\n");
		fclose(file2);
	}
	else
	{
		printf("Test Case 2: Failed to open the file.\n");
	}

	/* Test Case 3: NULL file path */
	char *nullFilePath = NULL;
	FILE *file3 = openThefiles(nullFilePath);

	if (file3 != NULL)
	{
		printf("Test Case 3: File opened successfully.\n");
		fclose(file3);
	}
	else
	{
		printf("Test Case 3: Failed to open the file.\n");
	}

	return (0);
}
