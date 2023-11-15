#include "main.h"

/**
 *divide_various_line - parses
 *@delim: separator
 *@buffer: holder of these group of words
 *Return: returns tokenized words until the end
 */

char **divide_various_line(char *buffer, const char *delim)
{
	char **string, *temp_stor, *tok = NULL;
	int checker = 0, index = 0;

	temp_stor = _strdup(buffer);
	tok = strtok(temp_stor, delim);
	for (; tok != NULL; checker++)
		tok = strtok(NULL, delim);
	if (checker == 0)
	{
		free(temp_stor);
		return (NULL);
	}
	string = malloc(sizeof(char *) * (checker + 1));
	if (string == NULL)
	{
		free(temp_stor);
		return (NULL);
	}
	tok = strtok(buffer, delim);
	while (tok != NULL)
	{
		string[index] = _strdup(tok);
		index++;
		tok = strtok(NULL, delim);
	}
	string[index] = NULL;
	free(temp_stor);
	return (string);
}
