#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * tokenize - Splits a string into token substrings.
 * @src_str: Source string to split into tokens.
 * @separator: Separator to use as splitter.
 *
 * Return: Pointer to dest array of strings.
 */

char **tokenize(char *src_str, const char *separator)
{
	int i = 0;
	int token_count = 0;
	char **dest_str_arr = NULL;
	char *token, *temp_str;

	/* Check for NULL passed arguments */
	if (src_str == NULL || separator == NULL)
		return (NULL);

	/* Calculate the number of tokens */
	temp_str = strdup(src_str);
	token = strtok(temp_str, separator);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, separator);
	}
	 free(temp_str);

	/* Allocate memory for the destination array of strings */
	dest_str_arr = malloc((token_count + 1) * sizeof(char *));
	if (dest_str_arr == NULL)
		return (NULL);

	/* Tokenize the string and store the tokens in the array */
	token = strtok(src_str, separator);
	while (token != NULL)
	{
		dest_str_arr[i] = token;
		i++;
		token = strtok(NULL, separator);
	}
	dest_str_arr[i] = NULL;
	
	free(src_str);
	return (dest_str_arr);
}
