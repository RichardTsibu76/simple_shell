#include "main.h"

/**
 *put_err - indicates error when command is not right
 *@prog_name: the name
 *@cmd: the command to be inputed
 *Return: Nothing to be returned
 */

int put_err(char *prog_name, char *cmd)
{
	/*this fucntion prints out the standerr of on the screen */
	/* that is if the command is invalid as stated */
	char *err_or = ": command not found\n";

	write(STDERR_FILENO, prog_name, _strlen(prog_name));
/* using the write system call provided by the kernel for user interaction*/
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, err_or, _strlen(err_or));
	/*isatty checks if the fd refers to the terminal*/
	return (127);
}
