#include "main.h"

/**
 *divide_various_line - parses each of the string and returns it
 *		until reaches NULL
 *@buffer: holder of these group of words
 *Return: returns tokenized words until the end
 */

char **divide_various_line(char *buffer)
{
	char **string, *temp_stor, *tok = NULL, *separator = " \v\b\n\t\r";
	int checker = 0, index = 0, k;

	temp_stor = _strdup(buffer);
	if (temp_stor == NULL)
		return (NULL);
	tok = strtok(temp_stor, separator);
	while (tok != NULL)
	{
		checker++;
		tok = strtok(NULL, separator);
	}
	checker++;
/* allocating memory dynamically */
	string = malloc(sizeof(char *) * checker);
	if (string == NULL)
	{
		free(temp_stor);
		return (NULL);
	}
	tok = strtok(buffer, separator);
	while (tok != NULL)
	{
		string[index] = _strdup(tok);
		if (string[index] == NULL)
		{
			for (k = 0; k < index; k++)
				free(string[k]);
			free(string);
			free(buffer);
			free(temp_stor);
			return (NULL);
		}
		index++;
		tok = strtok(NULL, separator);
	}
	string[index] = NULL;
	free(temp_stor);
	return (string);
}
