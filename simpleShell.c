#include "shell.h"
/**
 *  main - main arguments functions
 *  @ac:count of argumnents
 *  @av: arguments
 *  @env: environment
 *  Return: _exit = 0.
 */
int main(int ac, char **av, char **env)
{
	char *getcommand = NULL, **user_command = NULL;
	int pathValue = 0, _exit_ = 0, n = 0;
	(void)ac;

	while (1)
	{
		getcommand = _getline_command_();
		if (getcommand)
		{
			pathValue++;
			user_command = _get_token_(getcommand);
			if (!user_command)
			{
				free(getcommand);
				continue;
			}
			if ((!_strcmp_(user_command[0], "exit")) && user_command[1] == NULL)
				_exit_command_(user_command, getcommand, _exit_);
			if (!_strcmp_(user_command[0], "env"))
				_getenv_(env);
			else
			{
				n = _values_path_(&user_command[0], env);
				_exit_ = _fork_fun_(user_command, av, env, getcommand, pathValue, n);
				if (n == 0)
					free(user_command[0]);
			}
			free(user_command);
		}
		else
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(_exit_);
		}
		free(getcommand);
	}
	return (_exit_);
}
