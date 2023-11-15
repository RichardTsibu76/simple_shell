#include "main.h"
/**
*free_tokens - this function frees the buffer
*av: buffer to free
*Return
*/

void free_tokens(char **av)
{
	int i;

	if (av != NULL)
	{
		for (i = 0; av[i] != NULL; i++)
			free(av[i]);
		free(av);
	}
}
