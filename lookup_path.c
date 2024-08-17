#include "main.h"
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * get_path_env - Searches for the PATH environment variable.
 *
 *
 */
char *get_path_env(void)
{
	char *path = NULL;
	int i = 0;

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
		i++;
	}

	return path;
}
/**
 * lookup_path - Searches paths in PATH env variable to find binary location.
 * @func: function to lookup the binary file for.
 *
 * Return: void.
 */
char *lookup_path(const char *func)
{
	char *path = get_path_env();
	char *token = NULL;

	if (path == NULL)
	{
		printf("PATH not found\n");
		return (NULL);
	}

	while (token != NULL)
	{
		token = strtok(NULL, ":");
		if (access(strcat(token, func), X_OK))
			break;
	}

	return (strcat(token, func));
}
