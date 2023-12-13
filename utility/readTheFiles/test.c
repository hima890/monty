#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point for the test program.
 *
 * Return: Always 0.
*/
int main(void)
{
	/* Test Case 1: Valid file with text content */
	FILE *file1 = fopen("test_text.txt", "r");

	if (file1 != NULL)
	{
		char *buffer1 = readFiles(file1);

		if (buffer1 != NULL)
		{
			printf("Test Case 1: File contents:\n%s\n", buffer1);
			free(buffer1); /* Remember to free the allocated memory */
		}
		else
		{
			printf("Test Case 1: Failed to read the file.\n");
		}
		fclose(file1);
	}
	else
	{
		printf("Test Case 1: Failed to open the file.\n");
	}

	/* Test Case 2: Valid file with binary content */
	FILE *file2 = fopen("test.txt", "r");

	if (file2 != NULL)
	{
		char *buffer2 = readFiles(file2);

		if (buffer2 != NULL)
		{
			printf("Test Case 2: File contents (in hexadecimal):\n");
			for (size_t i = 0; buffer2[i] != '\0'; ++i)
			{
				printf("%c", (char)buffer2[i]);
			}
			printf("\n");
			free(buffer2); /* Remember to free the allocated memory */
		}
		else
		{
			printf("Test Case 2: Failed to read the file.\n");
			free(buffer2); /* Remember to free the allocated memory */
		}
	}
	else
	{
		printf("Test Case 2: Failed to open the file.\n");
	}

	/* Test Case 3: Invalid file pointer */
    FILE *file3 = NULL;
    char *buffer3 = readFiles(file3);
    if (buffer3 == NULL)
    {
        printf("Test Case 3: Invalid file pointer handled correctly.\n");
    }
    else
    {
        printf("Test Case 3: Unexpected result with an invalid file pointer.\n");
        free(buffer3); /* Remember to free the allocated memory */
    }

	return (0);
}
