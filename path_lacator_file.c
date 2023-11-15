#include "main.h"
/**
 *dealer_path - returns the path to a command
 *@cmd: arguments
 *Return: on successs, returns the path
 */
char *dealer_path(char *cmd)
{
	char **tok, *separator = ":", *pro_path, paths[BUFSIZ];
	int i = 0;
	struct stat st;

	if (stat(cmd, &st) == 0)
		return (_strdup(cmd));
	strcpy(paths,  _getenv(environ, "PATH"));
	if (cmd == NULL || paths == NULL)
		return (NULL);
	tok = divide_various_line(paths, separator);
	if (tok == NULL)
		return (NULL);
	for (; tok[i] != NULL; i++)
	{
		pro_path = malloc(sizeof(char) * (_strlen(cmd) + _strlen(tok[i]) + 2));
		if (pro_path == NULL)
			break;
		_strcpy(pro_path, tok[i]);
		_strcat(pro_path, "/");
		_strcat(pro_path, cmd);
		if (stat(pro_path, &st) == 0)
		{
			free_tokens(tok);
			return (pro_path);
		}
		free(pro_path);
	}
	free_tokens(tok);
	return (NULL);
}
