#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>

int get_lines(FILE *fileConnection);
char** get_commands(FILE *fileConnection);
int main(int argc, char *argv[]);

#endif
