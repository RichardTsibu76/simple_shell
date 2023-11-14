#include "main.h"

/**
 *invoke_fork - creates process
 *@argv: pointer to string
 *@prog_name: name
 *@entire_path: the path to the command
 *@env: where all current variables are found
 *Return: this returuns nothing it's void
 */
void invoke_fork(char **argv, char *prog_name, char *entire_path, char **env)
{
	pid_t Birthed_pid;
	int status;

	Birthed_pid = fork();
	if (Birthed_pid == -1)
	{
		perror(prog_name);
		exit(EXIT_FAILURE);
	}
	if (Birthed_pid == 0)
	{
		if (execve(entire_path, argv, env) == -1)
		{
			perror(prog_name);
			_exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		free(entire_path);
	}
}
