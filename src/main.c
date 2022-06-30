#include "main.h"

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_lines(FILE *fileConnection) {
  int count = 0;
  int ch = 0;

  /* make sure we go back to the beginning of the file */
  rewind(fileConnection);

  /* iterate through file to get line numbers */
  while (!feof(fileConnection)) {
    ch = fgetc(fileConnection);
    if (ch == '\n') {
      count++;
    }
  }

  /* return the line numbers */
  return count;
}

char** get_commands(FILE *fileConnection) {
  int i = 0;
  int count = 0;
  char *line = NULL;
  char ch;

  /* allocate array - reallocate once we know no. of lines*/
  char** ret = malloc(get_lines(fileConnection) * sizeof(char*));

  /* reset the file - we have to traverse the file to count lines */
  rewind(fileConnection);

  /* allocate a starting amount of memory for the string */
  line = (char *) malloc((i+1) * sizeof(char));

  /* traverse file - add each character to line*/
  while (!feof(fileConnection)) {
    /* get character */
    ch = fgetc(fileConnection);
    line = (char *) malloc((i+1) * sizeof(char));

    /* add to ret on new line */
    if (ch == '\n') {
      ret[count] = line;
      free(line);
      count++;
      i = 0;
    }

    i++;
  }

  /* now return the list of commands */
  return ret;
}

int main(int argc, char *argv[]) {
  char *filename;
  char** commands;
  char* next;
  int i;
  FILE *fp;

  /* command line args parser */
  for (int i = 0; i < argc; ++i) {
    if (strcmp(argv[i], "-f") == 0 && i != argc) {
      filename = argv[i+1];
    }
  }

  /* if no file, terminate */
  if (!filename) {
    fprintf(stderr, "ERR: No file provided\n");
    exit(EXIT_FAILURE);
  }

  /* open the file with the commands - terminate if fails */
  fp = fopen(filename, "r");
  if (!fp) {
    fprintf(stderr, "ERR: Can't open file\n");
    exit(EXIT_FAILURE);
  }

  /* allocate an array to store the commands from the file */
  commands = get_commands(fp);

  next = commands[0];
  while (next) {
    printf("%s\n", next);
    i++;
    next = commands[i];
  }

  /* close/free any memory allocated */
  fclose(fp);
  free(commands);

  /* terminate */
  return 0;
}
