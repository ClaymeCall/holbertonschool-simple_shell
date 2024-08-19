#include "main.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/**
* main - entry point function for simple shell.
*
* Return: 0 on success, -1 on failure.
*/
int main(void)
{
	char *buf = NULL, **argv = {NULL}, *cmd = NULL;
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
			printf("\n");
			exit(0);
		}

		cmd = buf;

		while (cmd[0] == ' ' || cmd[0] == '\t')
			cmd++;

		if (strcmp(cmd, "\n") == 0)
			continue;

		cmd[buf_len - 1] = '\0';

		argv = tokenize(lookup_path(cmd), " ");

		if (argv == NULL || argv[0] == NULL)
		{
			free(cmd);
			return (0);
		}

		execute(argv);
		free(buf);
		free(argv);
	}
	return (0);
}
