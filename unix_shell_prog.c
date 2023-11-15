#include "main.h"
/**
 *main - Simple shell, unix commandline interpreter
 *@ac: counter of arguments
 *@args: argumments
 *@env: The environment variable for the PATH
 *	of all executables.
 *Return: This returns 0 on success.
 */
int main(int ac, char **args, char **env)
{
	char *hold = NULL, **argv = NULL, *p_identity = args[0], *f_rout;
	size_t cal = 0, status = EXIT_SUCCESS;
	(void) ac;

	while (1)
	{
		signal(SIGINT, sigint_handler);
		if (isatty(STDIN_FILENO) == 1)
			put_prompt();
		if (getline(&hold, &cal, stdin) == -1)
			break;
		argv = divide_various_line(hold, "\t\n ");
		if (argv == NULL)
			continue;
		if (_strncmp(argv[0], "exit", 4) == 0)
		{
			free_tokens(argv);
			break;
		}
		if (_strncmp(argv[0], "env", 4) == 0)
		{
			status = penv();
			free_tokens(argv);
			continue;
		}
		f_rout = dealer_path(argv[0]);
		if (f_rout != NULL)
			status = invoke_fork(argv, p_identity, f_rout, env);
		else
			status = put_err(p_identity, argv[0]);
		free_tokens(argv);
	}
	revoke_f(hold);
	return (status);
}
