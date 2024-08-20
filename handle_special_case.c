#include "main.h"
#include <stdio.h>
#include <string.h>

/**
* handle_special_cases - Handle commands inherent to the shell.
* @cmd: Command to execute.
*
* Return: 0 on sucess.
*/
int handle_special_cases(char *cmd)
{
	char **env;
	char *this_env;

	if (strcmp(cmd, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (strcmp(cmd, "env") == 0)
	{
		for (env = environ; *env != 0; env++)
		{
			this_env = *env;
			printf("%s\n", this_env);
		}
	}

	return (0);
}
