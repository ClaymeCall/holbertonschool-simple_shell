#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
* main - entry point function for simple shell.
*
* Return: 0 on success, -1 on failure.
*/
int main(void)
{
	char *buf = NULL, **argv = {NULL}, *cmd = NULL, *full_path;
	size_t buf_size = 1024;
	ssize_t buf_len;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("UwU$ ");

		buf_len = getline(&buf, &buf_size, stdin);
		if (buf_len == EOF)
			break;

		cmd = buf;
		while (cmd[0] == ' ' || cmd[0] == '\t')
			cmd++;

		if (strcmp(cmd, "\n") == 0)
			continue;

		cmd[strlen(cmd) - 1] = '\0';

		handle_special_cases(cmd);

		full_path = lookup_path(cmd);

		if (full_path != NULL)
			argv = tokenize(full_path, " ");

		if (argv != NULL)
			execute(argv);

		free(full_path);
		free(argv);
	}
	free(buf);
	printf("\n");
	exit(0);
}
