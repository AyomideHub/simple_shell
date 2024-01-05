#include "main.h"

/**
 * display_prompt- print the shell and collect input
 *
 * Return: pointer on success
 */

char *display_prompt()
{

	char *cmd;
	size_t cmd_size = 0;
	ssize_t returnVal;

	if (isatty(0))
		write(1, "#cisfun$ ", 9);
	
	returnVal = getline(&cmd, &cmd_size, stdin);
	if (returnVal == -1)
	{
		write(1, "\n", 1);
		exit(0);
	}

	return (cmd);
}
