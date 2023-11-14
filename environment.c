#include "main.h"

/**
 *_getenv - this function deal with all the executables in the path
 *@env: this is where all currrent paths are located embedded in var
 *@name: anchor of variables
 *Return: on success, returns the path
 */

char *_getenv(char **env, char *name)
{
	int idx = 0, cont;

	cont = _strlen(name);
	while (env[idx] != NULL)
	{
		if (_strncmp(env[idx], name, cont) == 0)
			return (env[idx] + (cont + 1));
		idx++;
	}
	return (NULL);
}
