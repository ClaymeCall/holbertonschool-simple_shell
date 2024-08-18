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

		handle_special_cases(buf_len, buf);

		buf[buf_len - 1] = '\0';

		while ( buf[0] == ' ' || buf[0] == '\t')
			buf++;

		lookup_path(buf);

		argv = tokenize(buf, " ");

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
