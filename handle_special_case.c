#include "main.h"
#include <stdio.h>
#include <string.h>
#include <time.h>

/**
* handle_special_cases - Handle commands inherent to the shell.
* @cmd: Command to execute.
* @buf: Buffer to free in case of exit.
*
* Return: 0 on sucess.
*/
int handle_special_cases(char *cmd, char *buf)
{
	int i;

	if (strcmp(cmd, "exit") == 0)
	{
		free(buf);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(cmd, "env") == 0)
	{
		for (i = 0; environ[i] != NULL; i++)
			printf("%s\n", environ[i]);
	}

	return (0);
}
