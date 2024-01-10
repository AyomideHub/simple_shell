#include "main.h"

/**
 * builtInCmd - execute built in commands, cd, exit and env
 *
 * @Arg: Argument to be checked
 *
 * Return: 0 on success
 */

int builtInCmd(char **Arg)
{

	if (strcmp(Arg[0], "exit") == 0)
	{
		free(Arg);
		exit(0);
	}
	else if (strcmp(Arg[0], "cd") == 0)
	{
		if (Arg[1] == NULL)
		{
			chdir(getenv("HOME"));
			free(Arg);
			return (0);
		}
		else
		{
			chdir(Arg[1]);
			free(Arg);
			return (0);
		}
	} else
	{
		return (-1);
	}
}
