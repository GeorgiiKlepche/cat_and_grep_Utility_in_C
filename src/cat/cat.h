#ifndef CAT_H_
#define CAT_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int b;
    int e;
    int n;
    int s;
    int t;
    int v;
    int E;
    int T;
} arguments;

int parser(int countArg, arguments *opt, char **str);
int print_file(arguments opt, char *file_name, int count, int* lastChar);
void print_unprinted(arguments opt, int c);
void print_char(arguments opt, int c);

#endif  // CAT_H_
