#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * openfiles - This function opens the file specified by the given file path
 * in read-only mode and returns a pointer to the file.
 *
 * @filePath: A string pointer containing the file path.
 *
 * Return:
 *   - A file pointer if the file is successfully opened.
 *   - NULL if the file cannot be opened.
 *
 * Note:
 *   - Ensure that the file path is valid and accessible.
*/
FILE *openfiles(const char *filePath)
{
	/* Create the pointer to accsses the file from type "FILE"  */
	FILE *filePointer;

	/* Open the file in binary read mode */
	filePointer = fopen(filePath, "r");

	/* Check if the file is successfully opened */
	if (filePointer == NULL)
	{
		/* Print error message to the stander error output */
		fprintf(stderr, "Error: Can't open file %s\n", filePath);

		/* Return an error code NULL */
		return (NULL);
	}
	else
	{
		/* Return a file pointer */
		return (filePointer);
	}
}
