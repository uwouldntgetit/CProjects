#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_TIME_LENGTH 100

void eliminateChar(char* string, int position);
void noArguments(DIR* directory);
void useArguments(DIR* directory, char* args);
char *convertTime(time_t *x);
_Bool wrongOption(char* string);
_Bool inString(char* string, char check);
char* fileType(struct stat fs);

#endif
