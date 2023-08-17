#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PATH 100

void execmd(char **argv);
int cat(char **args);
int date(char **args);
int mkdir(char **args);
int rm(char **args);
int ls(char **args);
