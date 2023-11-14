#include "main.h"

/**
 *sigint_handler - works on effective signal handling
 *@sig_int: for user regardly for handling sig
 *Return: does not return anything its void
 */

void sigint_handler(int sig_int)
{
	/* this signal handling varies across unix version*/
	if (sig_int == SIGINT)
	{
		put_char('\n');
		put_prompt();
	}
} /* purposely for signals, though it's funtion varies across unix version */
