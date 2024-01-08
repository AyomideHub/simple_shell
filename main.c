#include "main.h"

/*
* main - shell command interpreter
*
*return (0);
*/

int main(void)
{
	char *command, *token, *exepath;
	char **Arg;
	int i = 0, status;


	while (1)
	{
		command = display_prompt();
		if (command == NULL)
			exit(0);

		token = strtok(command, " \t\n");

		Arg = malloc(sizeof(char *) * strlen(command) + 2);
		if (Arg == NULL)
			exit(0);

		while (token != NULL)
		{
			Arg[i] = token;
			token = strtok(NULL, " \t\n");
			i++;
		}
		Arg[i] = NULL;

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
		i = 0;
		free(Arg);
		
	}


	return (0);
}
