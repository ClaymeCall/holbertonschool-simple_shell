#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * execute - Execute a command and its arguments in a separate process.
 * @argv: Array of strings containing the command and arguments to execute.
 *
 * Return: 0 on success, -1 or 127 on failure.
 */
int execute(char **argv)
{
	int status;
	char *env[] = {NULL};
	pid_t pid;

	if (argv == NULL)
		return (-1);

	/* Fork current process into child process to execute new program */
	pid = fork();

	if (pid == -1)
	{
		free(argv);
		perror("Error");
		_exit(-1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			free(argv);
			perror("Execution failed");
			_exit(127);
		}
	}

	/* Parent process waits for child process end */
	else
		wait(&status);

	return (0);
}
