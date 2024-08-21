#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * tokenize - Splits a string into token substrings.
 * @src_str: Source string to split into tokens.
 * @separator: Separator to use as splitter.
 *
 * Return: Pointer to dest array of strings.
 */
char **tokenize(char *src_str, const char *separator)
{
	char *token;
	int i = 0;
	char **dest_str_arr = malloc(1024 * sizeof(char *));

	if (dest_str_arr == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	/* Tokenize the source string inside of the array */
	token = strtok(src_str, separator);
	while (token != NULL)
	{
		if (strlen(token) > 0)
		{
			dest_str_arr[i] = token;
			++i;
		}
		token = strtok(NULL, separator);
	}
	/* End the array with a NULL pointer */
	dest_str_arr[i] = NULL;

	return (dest_str_arr);
}
