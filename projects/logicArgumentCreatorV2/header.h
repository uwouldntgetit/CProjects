#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 1000
// secure input function
void getString(char *string, int length);
void generalFunction(int mode,int form);
void printArgumentForm(int form);
void specialization(char* s1, char* s2);
void elimination(char* s1, char* s2);

#endif
