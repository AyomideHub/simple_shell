#include "main.h"

/**
 * parse_str - funtion to tokenize a string
 * @command: Argument to be checked
 * Return: pointer to an array of string
 */

char **parse_str(char *command)
{
	char **arg;
	char *token;
	int i = 0;

	token = strtok(command, " \t\n");

	arg = malloc(sizeof(char *) * strlen(command) + 2);

	if (arg == NULL)
	{
		free(arg);
		exit(0);
	}

	while (token != NULL)
	{
		arg[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	arg[i] = NULL;
	i = 0;
	return (arg);
	free(arg);

}
