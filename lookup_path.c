#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * get_path_env - Searches for the PATH environment variable.
 *
 * Return: Double pointer to the PATH environment variable
 */
char *get_path_env(void)
{
	char *path = NULL;
	int i = 0;

	if (strncmp(environ[i] - 5, "PATH=", 5) == 0)
	{
		path = environ[i];
		return (environ[i]);
	}

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], "PATH=", 5) == 0)
		{
			path = environ[i] + 5;
			break;
		}
		i++;
	}

	if (path == NULL)
		printf("PATH environment variable not found\n");

	return (path);
}

/**
 * lookup_path - Searches paths in PATH env variable to find binary location.
 * @func: function to lookup the binary file for.
 *
 * Return: void.
 */
char *lookup_path(char *func)
{
	char *path = get_path_env();
	char *token = NULL, *full_path = NULL;
	char *path_copy = strdup(path);
	size_t len_token, len_func;

	if (path == NULL)
		return (NULL);

	if (access(func, X_OK) == 0)
	{
		free(path_copy);
		return (strdup(func));
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		len_token = strlen(token);
		len_func = strlen(func);

		/* Allocate memory for full_path (token + "/" + func + '\0') */
		full_path = malloc(len_token + 1 + len_func + 1);
		if (full_path == NULL)
		{
			free(path_copy);
			return (NULL);
		}
		/* Constructing the full path */
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, func);

		/* Return path if it is executable */
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	printf("%s: not found\n", func);
	return (NULL);
}
