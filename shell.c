#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
* main - main function for simple shell
*
* Return: Void
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

		if (buf[buf_len - 1] == '\n')
			buf[buf_len - 1] = '\0';

		argv = tokenize(buf, " ");

		if (argv == NULL)
		{
			free(buf);
			free(argv);
			return (0);
		}

		execute(argv);

		free(buf);
		free(argv);

	}
	return (0);
}
