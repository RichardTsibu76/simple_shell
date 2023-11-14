#include "main.h"

/**
 *executes - executes the parsed input
 *@argv: argumnts array pass
 *@prog_name: name
 *@entire_path: entire PATH for the executables
 *Return: Nothing it's void keyword
 */

void executes(char **argv, char *prog_name, char *entire_path)
{
	char **env = environ;

	if (argv)
	{

		if (execve(entire_path, argv, env) == -1)
		{
	/* prints error pro_name */
			perror(prog_name);
			_exit(2);
		}
	}
}
