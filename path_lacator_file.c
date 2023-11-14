#include "main.h"

/**
 *dealer_path - returns the path to a command
 *@cmd: arguments
 *@all_path: instant PATH
 *Return: on successs, returns the path
 */

char *dealer_path(char *cmd, char *all_path)
{
	char *tok, *comd, *separator = ":", *pro_path, *all_path_cp;
	int c_length, tk_l;
	struct stat st;

	if (cmd == NULL || all_path == NULL)
		return (NULL);
	c_length = _strlen(cmd);
	all_path_cp = _strdup(all_path);
	if (all_path_cp == NULL)
		return (NULL);
	tok = strtok(all_path_cp, separator);
	while (tok != NULL)
	{
		tk_l = _strlen(tok);
	pro_path = malloc(sizeof(char) * (tk_l +	c_length + 2));
		if (pro_path == NULL)
		{
			free(all_path_cp);
			return (NULL);
		}
		_strcpy(pro_path, tok);
		_strcat(pro_path, "/");
		_strcat(pro_path, cmd);
		if (stat(pro_path, &st) == 0)
		{
			free(all_path_cp);
			return (pro_path);
		}
/* deallocating the memory for the allocated memory in space*/
		free(pro_path);
/* parsing or tokenizing */
		tok = strtok(NULL, separator);
	}
	free(all_path_cp);
	comd = _strdup(cmd);
	if (stat(comd, &st) == 0)
		return (comd);
	free(comd);
	return (NULL);
}
