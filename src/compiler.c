#include "compiler.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* split a line from the file into labels, opcodes and operands */
char** split_line(char* line) {
  char** ret = malloc(3 * sizeof(char*));

  int i = 0;
  int usefulChars = 0;
  int count = 0;
  char current = line[i];
  char* currentItem = malloc((i+1) * (sizeof(char)));

  while (1) {
    /* get current character */
    current = line[i];

    /* if char is terminate char, break */
    if (current == -1) {
      free(currentItem);
      break;
    }

    /* if we come to the end of a useful string - add to ret */
    if ((usefulChars > 1) & (current == ' ')) {
      ret[count] = strdup(line);
      count++;
      usefulChars = 0;
      continue;
    }

    /* collect characters that aren't a space */
    if (current != ' ') {
      currentItem = realloc(line, (usefulChars+1) * sizeof(char));
      currentItem[usefulChars] = current;
      usefulChars++;
    }

    i++;
  }

  return ret;
}

int compile(char** commands) {
  char** broken_line = split_line(commands[0]);
  int i = 0;
  char* next = commands[i];

  /* free each element of the broken line */
  i = 0;
  next = broken_line[i];
  while (next) {
    free(next);
    i++;
    next = broken_line[i];
  }

  /* terminate */
  return 0;
}
