#include "main.h"
#include <cstdio>
#include <stdio.h>
#include <unistd.h>

/**
 * execute - Execute the command line pass by stdin.
 * @argv: Command pass by stdin.
 *
 * Return : 0 on succes -1 on failure.
 */

int execute(char **argv)
{
	int status;
	char *env[] = {NULL};
	pid_t pid;

	if (argv == NULL)
		return (-1);

	/* Fork a child process to execute new program */
	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		free(argv);
		_exit(-1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Execution failed");
			free(argv);
			_exit(-1);
		}
	}

	/* parent process wait child end of process */
	else
	{
		wait(&status);
	}
	return (0);
}
