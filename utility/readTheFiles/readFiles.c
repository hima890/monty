#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * readFiles - Reads the contents of a file into a dynamically allocated
 * buffer.
 *
 * @filePointer: A file pointer to the file.
 *
 * Return:
 *   - A string buffer with the file contents.
 *   - NULL if there is an error (e.g., file not found, memory allocation
 * failure).
 *
 * Notes:
 *	 - Caller is responsible for freeing the allocated memory(buffer).
*/
char *readFiles(FILE *filePointer)
{
	/* Check if the file pointer is valid */
	if (filePointer == NULL)
	{
		fprintf(stderr, "Error: Invalid file pointer.\n");
		return (NULL);
	}

	/* Initialize variables for file size and buffer */
	long fileSize;
	char *buffer;

	/* Move the file position indicator to the end of the file */
	fseek(filePointer, 0, SEEK_END);
	/* Get the current position of the file pointer (file size) */
	fileSize = ftell(filePointer);
	/* Move the file position indicator back to the beginning of the file */
	fseek(filePointer, 0, SEEK_SET);

	/* Allocate memory for the entire file content (+1 for null terminator) */
	buffer = (char *)malloc(fileSize + 1);

	/* Check if memory allocation is successful */
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: Memory allocation failed.\n");
		fclose(filePointer);
		return (NULL);
	}

	/* Read the entire file into the buffer */
	fread(buffer, fileSize, 1, filePointer);

	/* Add a null terminator at the end of the buffer */
	buffer[fileSize] = '\0';

	/* Close the file */
	fclose(filePointer);

	/* Return the buffer */
	return (buffer);
}
