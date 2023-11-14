#include "main.h"

/**
 *deal_with_quote - deals with quotes, and tokenizes
 *@buffer: temporal storage for tokenization
 *@string: buffer for tokenized words
 *Return: parsed string
 */


char **deal_with_quote(char *buffer, char **string)
{
	char *buf_tok, *parser, *e_qo, *separator = " \"\t\r\n";
	int index = 0, j;

	buf_tok = _strdup(buffer);
	parser = strtok(buf_tok, separator);
	while (parser != NULL)
	{
		if (parser[0] == '"')
		{
			e_qo = _strchr(parser + 1, '"');
			if (e_qo != NULL)
			{
				*e_qo = '\0';
				string[index] = _strdup(parser + 1);
			}
			else
				string[index] = _strdup(parser);
		}
		else
			string[index] = _strdup(parser);
		if (string[index] == NULL)
		{
			for (j = 0; j < index; j++)
				free(string[j]);
			free(string);
			free(buf_tok);
			return (NULL);
		}
		index++;
		parser = strtok(NULL, separator);
	}
	string[index] = NULL;
	return (string);
}
