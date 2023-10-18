#include "shell.h"
/**
 *  _get_path_ - get variable PATH.
 *  @env: enviromente local
 *  Return: value of PATH.
 */

char *_get_path_(char **env)
{
	size_t i = 0, var = 0, count = 5;
	char *path = NULL;

	for (i = 0; _strncmp_(env[i], "PATH=", 5); i++)
		;
	if (env[i] == NULL)
		return (NULL);

	for (count = 5; env[i][var]; var++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));

	if (path == NULL)
		return (NULL);

	for (var = 5, count = 0; env[i][var]; var++, count++)
		path[count] = env[i][var];

	path[count] = '\0';
	return (path);
}
