#include "shell.h"
/**
 *  _fork_fun_ - function that create a fork
 *  @arg: command and values path
 *  @av: Has the name of our program
 *  @env: environment
 *  @lineptr: command line for the user
 *  @np: id of proces
 *  @c: Checker add new test
 *  Return: 0 success
 */

int _fork_fun_(char **arg, char **av, char **env, char *lineptr, int np, int c)
{
	pid_t child;
	int state;
	char *format = "%s: %d: %s: not found\n";

	child = fork();

	if (child == 0)
	{
		if (execve(arg[0], arg, env) == -1)
		{
			fprintf(stderr, format, av[0], np, arg[0]);
			if (!c)
				free(arg[0]);
			free(arg);
			free(lineptr);
			exit(errno);
		}
	}
	else
	{
		wait(&state);

		if (WIFEXITED(state) && WEXITSTATUS(state) != 0)
			return (WEXITSTATUS(state));
	}
	return (0);
}
