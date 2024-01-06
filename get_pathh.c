#include "main.h"


char * filepath(char *path, char *Arg)
{
	char *path2 = strdup(path);

	char *pathtoken = strtok(path2, ":");

	char *real_path = malloc(sizeof(char ) * strlen(Arg) + 2);

	while (pathtoken != NULL)
	{
		strcpy(real_path, pathtoken);
		strcat(real_path, "/");
		strcat(real_path, Arg);
		strcat(real_path, "\0");

		if (access(real_path, X_OK) == 0)
		{
			return (real_path);
		}

		pathtoken = strtok(NULL, ":");

	}
	free(real_path);
	free(path2);


	return (NULL);
}



char * get_path(char* Arg)
{
	char *path = getenv("PATH");

	char *final_path;

	if (path != NULL)
	{
		final_path = filepath(path, Arg);
		return (final_path);
	}

	return (NULL);
}
