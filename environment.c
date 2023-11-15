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
/**
*penv - a file
*Return: void deos not ret
*/
int penv(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(1, environ[i], _strlen(environ[i]));
		put_char('\n');
		i++;
	}
	return (0);
}
