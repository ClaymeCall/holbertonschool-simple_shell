#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * execute - Execute the command line pass by stdin
 * @argv: Command pass by stdin
 *
 * Return : void
 */

void execute(char **argv)
{
	int status;
	char *env[] = {NULL};
	pid_t pid;

	if (argv == NULL)
		return;

	/* Fork a child process to execute new program */
	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return;
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Execution failed");
			_exit(EXIT_FAILURE);
		}
	}

	/* parent process wait child end of process */
	else
	{
		wait(&status);
	}
}
