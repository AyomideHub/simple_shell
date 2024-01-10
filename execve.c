#include "main.h"

/**
 * execute_command - execute the coomand from the stdin
 * @Arg: Argument to be checked
 */

void execute_command(char **Arg)
{
	int status;
	char *exepath;

	if (builtInCmd(Arg) == -1)
	{
		if (access(Arg[0], X_OK) == 0)
		{
			if (fork() != 0)
			{
				wait(&status);
			} else
			{
				if (execve(Arg[0], Arg, NULL) == -1)
					perror("Error: command not found");
			}
		} else
		{
			exepath = get_path(Arg[0]);
			if (fork() != 0)
				wait(&status);
			else
			{
				if (execve(exepath, Arg, NULL) == -1)
					perror("Error: command not found");
			}
		}
	}
}
