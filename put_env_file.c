#include "main.h"

/**
 *put_env - prints the current env.
 *@env: a pointer to the string of the environ.
 *Return: the bool type does return
 */

bool put_env(char **env)
{
	int index = 0, length;

	while (env[index] != NULL)
	{
		length = 0;
		while (env[index][length] != '\0')
			length++;

		write(STDOUT_FILENO, env[index], length);
		put_char('\n');
		index++;
	}
	return (true);
}
