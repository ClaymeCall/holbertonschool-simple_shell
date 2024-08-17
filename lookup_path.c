#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

extern char **environ;

/**
 * get_path_env - Searches for the PATH environment variable.
 *
 * Return: Double pointer to the PATH environment variable
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

	return (path);
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
	char *full_path = NULL;
	size_t len_token, len_func;

	if (path == NULL)
	{
		printf("PATH not found\n");
		return (NULL);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		len_token = strlen(token);
		len_func = strlen(func);

		/* Allocate memory for full_path (token + "/" + func + '\0') */
		full_path = malloc(len_token + 1 + len_func + 1);
		if (full_path == NULL)
			return (NULL);

		/* Constructing the full path */
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, func);

		/* Return path if it is executable */
		if (access(full_path, X_OK) == 0)
			return (full_path);

		/* Free memory if path is not executable */
		free(full_path);
		token = strtok(NULL, ":");
	}

	return (NULL);
}
