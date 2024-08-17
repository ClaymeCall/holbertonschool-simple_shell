#include "main.h"
#include <stdio.h>

int main(void)
{
	int i = 0;
	char **argv = NULL;
	char buf[] = "/bin/ls -l -a";

		printf("Calling tokenize in main function");
	argv = tokenize(buf, " ");

		printf("Entering test main while");
	while (argv[i])
	{
		printf("%s\n", argv[i]);
		++i;
	}

	free(argv);

	return (0);
}
