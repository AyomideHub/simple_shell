#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

char *display_prompt();
char * get_path(char* Arg);
char * filepath(char *path, char *Arg);

#endif /* MAIN_H */
