#include "shell.h"
/**
 *  _exit_command_ - this function closes the simple_shell when
 *  @arg: pointer with the direction argument.
 *  @lineptr: standar input string
 *  @_exit_: value of exit
 *  Return: None
 */
void _exit_command_(char **arg, char *lineptr, int _exit_)
{
	int exit_state = 0;

	if (!arg[1])
	{
		free(lineptr);
		free(arg);
		exit(_exit_);
	}
	exit_state = atoi(arg[1]);

	free(lineptr);
	free(arg);
	exit(exit_state);
}

/**
 *  _getenv_ - function to get all envm
 *  @env: enviroment
 *  Return: 0
 */

void _getenv_(char **env)
{
	size_t go = 0;

	while (env[go])
	{
		write(STDOUT_FILENO, env[go], _strlen_(env[go]));
		write(STDOUT_FILENO, "\n", 1);
		go++;
	}
}
