#include "main.h"

/*
* main - shell command interpreter
*
*return (0);
*/

int main(void)
{
	char *command, *token;
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

		if (fork() != 0)
			wait(&status);
		else
		{
			if (execve(Arg[0], Arg, NULL) == -1)
				perror("Error");

			write(1, "\n", 1);
		}
		i = 0;
		free(Arg);
		
	}


	return (0);
}
