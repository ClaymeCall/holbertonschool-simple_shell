#include "main.h"
#include <stdio.h>

/**
* handle_special_cases - Handle special cases.
* @buf: Command passed in stdin.
* @buf_len: Size of buf.
*
* Return: 0 on sucess, 1 on failure.
*/
int handle_special_cases(char *buf, ssize_t buf_len)
{
	if (buf_len == EOF)
	{
		free(buf);
		printf("\n");
		return (0);
	}

	if (buf_len == 1 && buf[0] == '\n')
	{
		free(buf);
		printf("\n");
		return (0);
	}
	return (0);
}
