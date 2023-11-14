#include "main.h"

/**
 *white_space - clears white spaces
 *@t_buf: temporal storage
 *@argv: parsed string which is an array
 *Return: this beautifully returns the length
 */

size_t white_space(char **argv, char *t_buf)
{
	size_t length;
	int idx;

	while (*t_buf && (*t_buf == ' ' || *t_buf == '\t' ||
				*t_buf == '"'))
		t_buf++;
	length = _strlen(t_buf);
	while (length > 0 && (t_buf[length - 1] == ' ' || t_buf[length - 1] == '"' ||
				t_buf[length - 1] == '\t' || t_buf[length - 1] == '\n'))
	{
		t_buf[length - 1] = '\0';
		length--;
	}
	if (argv != NULL)
	{
		for (idx = 0; argv && argv[idx]; idx++)
			free(argv[idx]);
		free(argv);
	}
	return (length);
}
