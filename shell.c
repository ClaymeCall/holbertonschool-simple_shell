#include "main.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * check_eof - Handles EOF
 * @len: Size to check.
 * @buf: Buffer to free in case of EOF.
 *
 * Return: void
 */
void check_eof(ssize_t len, char *buf)
{
	if (len == EOF)
	{
		free(buf);
		if (isatty(STDIN_FILENO))
			printf("\n");
		exit(0);
	}
}

/**
* main - Entry point function for simple shell.
*
* Return: 0 on success.
*/
int main(void)
{
	char *buf = NULL, **argv = {NULL}, *cmd = NULL, *full_path = NULL;
	size_t buf_size = 1024;
	ssize_t buf_len;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("UwU$ ");

		buf_len = getline(&buf, &buf_size, stdin);
		check_eof(buf_len, buf);

		cmd = buf;
		while (cmd[0] == ' ' || cmd[0] == '\t')
			cmd++;

		if (strcmp(cmd, "\n") == 0)
			continue;

		cmd[strlen(cmd) - 1] = '\0';

		handle_special_cases(cmd, buf);

		argv = tokenize(cmd, " \t");

		full_path = lookup_path(argv[0]);
		if (full_path != NULL)
			argv[0] = full_path;

		if (argv != NULL)
			execute(argv);

		if (full_path != NULL)
			free(argv[0]);
		free(argv);
	}
	free(buf);
	return (0);
}
