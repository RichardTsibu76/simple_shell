#include "main.h"

/**
 *exiting_shell - exits the shell
 *@argv: The array of strings
 *Return: This returns either true or false
 */

bool exiting_shell(char **argv)
{
	if ((_strcmp(argv[0], "exit")) == 0)
		return (true);
	return (false);
}
