#include <stdio.h>

int main()
{
	FILE *filePointer;
	char buffer[1000]; // Adjust the size based on your needs
	size_t bytesRead;

	// Open the file in read mode
	filePointer = fopen("test.txt", "r");

	// Check if the file is successfully opened
	if (filePointer == NULL)
	{
		printf("Error opening the file.\n");
		return 1; // Return an error code
	}

	// Read the entire content of the file into the buffer
	bytesRead = fread(buffer, 1, sizeof(buffer) - 1, filePointer);

	// Check for read errors or end-of-file
	if (ferror(filePointer) != 0)
	{
		printf("Error reading the file.\n");
		fclose(filePointer);
		return 1; // Return an error code
	}

	// Null-terminate the buffer to make it a valid C string
	buffer[bytesRead] = '\0';

	// Print the entire content of the file
	printf("%s", buffer);

	// Close the file
	fclose(filePointer);

	return 0; // Return 0 to indicate success
}
