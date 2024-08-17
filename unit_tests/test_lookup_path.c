#include "../main.h"

int main(void)
{
	char *found_path = lookup_path("ls");

	if (found_path != NULL)
	{
		printf("Found path: %s\n", found_path);
		free(found_path);
	}
	else
		printf("Binary not found in PATH\n");

	return (0);
}
