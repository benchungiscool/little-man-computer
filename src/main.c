#include "main.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lines(FILE *fileConnection) {
  int count = 0;
  int ch = 0;

  // make sure we go back to the beginning of the file
  rewind(fileConnection);

  // iterate through file to get line numbers
  while (!feof(fileConnection)) {
    ch = fgetc(fileConnection);
    if (ch == '\n') {
      count++;
    }
  }

  // return the line numbers
  return count;
}

// returns a list of all the commands in a file
char** get_commands(FILE *fileConnection) {
  int size = get_lines(fileConnection);
  int count = 1;
  char* temp;
  char* ret[size];
  char ch;

  // rewind the file
  rewind(fileConnection);

  // Allocate a starting amount of memory for temporary string
  temp = malloc(100);

  // step through file - adding each line to array
  for (int i = 0; i < size; ++i) {
    fgets(temp, 100, fileConnection);
    puts(temp);
    memcpy(ret[i], temp, 100);
  }

  for (int i = 0; i < size; ++i) {
    puts(ret[i]);
  }
  // return the array
  return ret;
}

int main(int argc, char** argv) {
  char **commands;
  FILE *fp;
  char *filename;

  // command line args parser
  for (int i = 0; i < argc; ++i) {
    if (strcmp(argv[i], "-f") == 0 && i != argc) {
      filename = argv[i+1];
    }
  }

  // if no file, terminate
  if (!filename) {
    fprintf(stderr, "ERR: No file provided\n");
    exit(EXIT_FAILURE);
  }

  // open the file with the commands - terminate if fails
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "ERR: Can't open file\n");
    exit(EXIT_FAILURE);
  }

  commands = get_commands(fp);
}
