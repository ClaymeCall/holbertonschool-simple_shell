#include "main.h"
#include <cerrno>
#include <cstdio>
#include <stdio.h>
#include <unistd.h>

/**
* main - main function for simple shell
*
* Return: Return 0 on succes or -1 on failure
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

		if (buf_len == -1)
		{
			perror("getline");
			free (buf);
			return (1);
		}

		if (buf_len == EOF)
		{
			free(buf);
			exit(0);
		}

		if (buf[buf_len - 1] == '\n')
			buf[buf_len - 1] = '\0';

		argv = tokenize(buf, " ");

		if (strcmp(argv[0], "exit") == 0)
		{
			free(buf);
			free (argv);
			return (0);
		}

		if (argv == NULL)
		{
			free(buf);
			return (0);
		}

		if (execute(argv) == -1)
		{
			perror("not found");
			return (1);
		}
		free(argv);
	}
	return (0);
}
