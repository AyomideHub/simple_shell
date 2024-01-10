#include "main.h"

/**
 * display_prompt- print the shell and collect input
 *
 * Return: pointer on success
 */

char *display_prompt()
{

	char *cmd = malloc(3);
	size_t cmd_size = 3;
	ssize_t Val;

	if (isatty(0))
		write(1, "#cisfun$ ", 9);

	Val = getline(&cmd, &cmd_size, stdin);

	if (Val == -1)
	{
		write(1, "\n", 1);
		free(cmd);
		exit(0);
	}

	return (cmd);
	free(cmd);
}
