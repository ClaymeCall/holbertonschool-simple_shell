#include "main.h"
#include <stddef.h>
#include <stdio.h>

/**
 * check_spaces - Check if the string is only composed with space.
 * @buf: Command passed by stdin.
 * @buf_len: Size of the command passed by stdin.
 *
 * Return: 0 on success, -1 on failure.
 */
int check_spaces(char *buf, ssize_t buf_len)
{
	int i;

	/* Replace \n with \0 to properly terminate the string*/
	if (buf[buf_len - 1] == '\n')
		buf[buf_len - 1] = '\0';

	for (i = 0; i < buf_len - 1; i++)
	{
		if (buf[i] != ' ')
			return (1);
	}
	return (0);
}
