#include "main.h"

/*
* main - shell command interpreter program in c
* @void: no Argunment
* Return (0);
*/

int main(void)
{
	char *command;
	char **Arg;


	while (1)
	{
		command = display_prompt();
		if (command == NULL)
			exit(0);

		Arg = parse_str(command);

		execute_command(Arg);
	}

	free(Arg);
	free(command);
	return (0);
}
