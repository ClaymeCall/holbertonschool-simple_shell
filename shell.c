#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
* main - entry point function for simple shell.
*
* Return: 0 on success, -1 on failure.
*/
int main(void)
{
	char *buf = NULL, **argv = {NULL};
	size_t buf_size = 1024;
	ssize_t buf_len;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		buf_len = getline(&buf, &buf_size, stdin);

		if (buf_len == EOF)
		{
			free(buf);
			exit(0);
		}

		/* Check if getline fails and handles error */
		if (buf_len == -1)
		{
			perror("getline function error");
			free(buf);
			return (1);
		}

		/* Replace \n with \0 to properly terminate the string*/
		if (buf[buf_len - 1] == '\n')
			buf[buf_len - 1] = '\0';

		argv = tokenize(buf, " ");

		/**
		 *
		 * this gonna go in built_in_func
		 * if (strcmp(argv[0], "exit") == 0)
		 * {
		 *	free(buf);
		 *	free (argv);
		 *	return (0);
		 * }
		 */

		if (argv == NULL)
		{
			free(buf);
			return (0);
		}

		if (execute(argv) == -1)
		{
			perror("Function not found");
			return (1);
		}
		free(argv);
	}
	return (0);
}
