#include "main.h"

/*
* main - shell command interpreter
*
*return (0);
*/

int main()
{
    char dispay_prompt[] = "$ ";
    char *container, *duplicate;
    size_t size = 0;
    ssize_t container_val;

    while(1)
    {
        printf("%s",dispay_prompt);
        container_val = getline(&container, &size, stdin);

        if (container_val == -1)
        {
            return (-1);
        }

        duplicate = malloc(sizeof(char) * container_val);
        if (duplicate == NULL)
        {
            perror("Error\n");
            return (-1);
        }
    }


    free(container);
    free(duplicate);
    return 0;
}
