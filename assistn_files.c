#include "main.h"

/**
 *put_char - Prints characters
 *@c: character
 *Return: it returns what is printed
 */

int put_char(char c)
{	/* the write function taking fd, buf and len */
	return (write(STDOUT_FILENO, &c, 1));
}


/**
 *put_prompt - this displays prompt on standard output
 *Return: does not return anything
 */

void put_prompt(void)
{	/* the prompt to print */
	char *prompt = "$ ";
	int index = 0;

	while (prompt[index])
	{
		put_char(prompt[index]);
		index++;
	}
}


/**
 *_strdup - this is string duplicate
 *@str: constant string
 *Return: this returns a pointer
 */

char *_strdup(char *str)
{
	int index = 0, len = 0;
	char *dup = NULL;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	dup = malloc((len + 1) * sizeof(char));
	if (dup != NULL)
	{
		for (index = 0; index <= len; index++)
			dup[index] = str[index];
	}
	else
		dup = NULL;
	return (dup);
}

/**
 *_strchr - its look char in str
 *@s: a pointer variable
 *@c: a char to be looked for
 *Return: The string after where the character is found
 */

char *_strchr(char *s, char c)
{
	while (1)
	{
		if (*s == c)
			return (s);
		if (*s == '\0')
			return (NULL);
		s++;
	}
}
