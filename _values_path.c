#include "shell.h"
/**
 *  _values_path_ - separate the path in new strings.
 *  @arg: command input of user.
 *  @env: enviroment.
 *  Return:  a pointer to strings.
 */
int _values_path_(char **arg, char **env)
{
	char *token = NULL, *path_rela = NULL, *path_absol = NULL;
	size_t value_path, command;
	struct stat stat_lineptr;

	if (stat(*arg, &stat_lineptr) == 0)
		return (-1);
	path_rela = _get_path_(env);
	if (!path_rela)
		return (-1);
	token = _strtok_(path_rela, ":");
	command = _strlen_(*arg);
	while (token)
	{
		value_path = _strlen_(token);
		path_absol = malloc(sizeof(char) * (value_path + command + 2));
		if (!path_absol)
		{
			free(path_rela);
			return (-1);
		}
		path_absol = _strcpy_(path_absol, token);
		_strcat_(path_absol, "/");
		_strcat_(path_absol, *arg);

		if (stat(path_absol, &stat_lineptr) == 0)
		{
			*arg = path_absol;
			free(path_rela);
			return (0);
		}
		free(path_absol);
		token = _strtok_(NULL, ":");
	}
	free(path_rela);
	return (-1);
}
