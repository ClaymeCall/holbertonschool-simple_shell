#include "main.h"
#include <stdio.h>

int main(void)
{
	int status, fd, i;
	pid_t pid;
	char *token, **argv;
	char *env[] = {NULL};
	size_t bufsize = 1024;
	ssize_t line_len = 0;

	argv = malloc(bufsize * sizeof(char *));
	if (argv == NULL)
		exit(1);

	while (1)
	{
		printf("$ :");
		line_len = getline(argv, &bufsize, stdin);

		if (line_len == EOF)
		{
			free(argv);
			exit(0);
		}

		pid = fork();
		if (pid == -1)
		{
			perror("Error");
			return (1);
		}
		if (pid == 0) {
			i = 1;
			argv[0] = (strtok(token, " "));

			while (token)
			{
				token = (strtok(NULL, " "));
				argv[i] = token;
				++i;
			}

			argv[i] = "NULL";
			execve(argv[0], argv + 1, env);
		}
		else
		wait(&status);

	}

	free(argv);
	return (0);
}
