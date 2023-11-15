#include "main.h"

/**
 *revoke_f - this function handles contrl + D, does interfere
 *@buffer: storage for the for getline reads
 *Return: Nothing its void
 */

bool revoke_f(char *buffer)
{
	/* using the isatty which checks if fd refers to the terminal */
	if (isatty(STDIN_FILENO) == 1)
		put_char('\n');
	free(buffer);
	return (true);
}
