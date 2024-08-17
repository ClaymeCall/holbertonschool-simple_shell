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
			printf("\n");
			exit(0);
		}

		if (buf_len == -1)
		{
			perror("getline");
			free(buf);
			return (1);
		}

		if (buf_len == 1 && buf[0] == '\n')
			continue;

		/* if (space_checker(buf, buf_len) == 0)
			continue;
			*/

		argv = tokenize(buf, " ");

		/* maybe do this in tokenize at line for dest_src_str */
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
