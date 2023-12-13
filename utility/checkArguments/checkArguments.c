#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * checkArguments - Check the number of command-line arguments.
 *
 * @argc: The number of command-line arguments.
 *
 * Return:
 * - On success (when argc is 2), return 0.
 * - On failure or incorrect number of arguments, print an error message to
 *   stderr and return 1.
 *
 * Description:
 * - This function is used to ensure that the correct number of command-line
 *   arguments is provided.
 * - If the number of arguments is not 2, it prints an error message and
 *  returns 1.
 * - If the number of arguments is 2, it returns 0 to indicate success.
*/
int checkArguments(int argc)
{
	/* Check of the argument number is 2 */
	if (argc != 2)
	{
		/* If not print error message to the stander error output */
		fprintf(stderr, "USAGE: monty file\n");
		/* Return non zero value (1) o indicate failure */
		return (1);
	}
	else
	{
		/* If it 2 return (0) to indicate success */
		return (0);
	}
}
