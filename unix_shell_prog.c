#include "main.h"
/**
 *main - Simple shell, unix commandline interpreter
 *@ac: counter of arguments
 *@args: argumments
 *@env: The environment of variable for the PATH
 *		for all the executables
 *Return: This returns 0 on success
 */
int main(int ac, char **args, char **env)
{
char *hold = NULL, **argv = NULL, *p_identity = args[0];
	char *paths, *f_rout = NULL;
	size_t cal = 0, index, cal_len;
	ssize_t _show;
	(void) ac;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO) == 1)
			put_prompt();
		_show = getline(&hold, &cal, stdin);
		if ((_show == -1) && revoke_f(argv, hold))
			exit(EXIT_SUCCESS);
		cal_len = white_space(argv, hold);
		if (cal_len == 0)
		{
			continue;
		}
		argv = divide_various_line(hold);
		if (exiting_shell(argv) || (_strncmp(argv[0], "exit", 4) == 0))
		{
			free(hold);
			exit(EXIT_SUCCESS);
		}
		paths = _getenv(env, "PATH");
		f_rout = dealer_path(argv[0], paths);
		if (f_rout != NULL)
			invoke_fork(argv, p_identity, f_rout, env);
		else
			put_err(p_identity, argv[0]);

	}
	for (index = 0; argv && argv[index]; index++)
		free(argv[index]);
	free(argv);
	free(f_rout);
	free(hold);
	return (EXIT_SUCCESS);
}
