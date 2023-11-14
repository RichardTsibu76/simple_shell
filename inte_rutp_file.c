#include "main.h"

/**
 *revoke_f - this function handles contrl + D, does interfere
 *@buffer: storage for the for getline reads
 *@argv: parsed string
 *Return: Nothing its void
 */

bool revoke_f(char **argv, char *buffer)
{
	int index;
/* using the isatty which checks if fd refers to the terminal */
	if (isatty(STDIN_FILENO) == 1)
		put_char('\n');
	if (argv != NULL)
	{
		for (index = 0; argv && argv[index]; index++)
			free(argv[index]);
		free(argv);
	}
	free(buffer);
	return (true);
}
