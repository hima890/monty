#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "main.h"
#define MAX_LINE_LENGTH 256

/**
 * isStringInteger - Checks if a string represents an integer.
 *
 * @str: The string to check.
 *
 * Description:
 *   Determines if the given string represents a valid integer.
 *   It uses the strtol function to attempt to convert the string
 * to an integer.
 *   If the conversion is successful and there are no extra characters
 *   (other than whitespaces, newline, or null terminator) after the integer,
 *   it returns 1 (true), indicating that the string is a valid integer.
 *   Otherwise, it returns 0 (false).
 *
 * Parameters:
 *   - str: The string to check.
 *
 * Return:
 *   1 if the string represents an integer, 0 otherwise.
 *
 * Example:
 *   isStringInteger("123") returns 1
 *   isStringInteger("abc") returns 0
*/
int isStringInteger(char *str)
{
	char *endptr;

	strtol(str, &endptr, 10);

	if (*endptr != '\0' && *endptr != '\n' && !isspace(*endptr))
	{
		return (0);
	}

	return (1);
}
