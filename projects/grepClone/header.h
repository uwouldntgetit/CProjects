#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// macros for error checking
#define FAIL_IF(expression) ({if(expression){exit(EXIT_FAILURE);}})
#define FAIL_IF_MSG(exp, msg) ({if(exp){fprintf(stderr, msg ); exit(EXIT_FAILURE);}})
// use it only if the function called modifies errno
#define FAIL_IF_PERROR(exp, msg) ({if(exp){perror(msg); exit(EXIT_FAILURE);}})
#define MAX_LINE_LENGTH 2048

struct vl_matrix{
    int num_elems;
    char **matrix;
};



#endif
