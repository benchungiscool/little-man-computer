#ifndef MAIN_H_
#define MAIN_H_

#include "compiler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lines(FILE *fileConnection);
char** get_commands(FILE *fileConnection);
int main(int argc, char *argv[]);

#endif
