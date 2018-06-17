/*
  Catalog array will be an array of pointers to structs, each struct being a course
  from the list of courses in the supplied database. This will allow their properties
  to be altered, like changing the number of credits a course is worth.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "catalog.h"
#include "prompts.h"

int int main(int argc, char const *argv[]) {

  char *filepath;
  if (argc = 2) {
    filepath = malloc(strlen(argv[1]+1));
    strcpy(filepath, argv[1]);
  } else {
    printf("Error: Not the right number of input arguments.\n");
    return -1;
  }

  FILE *fp = fopen(filepath, "r");

  int line_count = 0;
  char line[50];
  while (fgets(line, 50, fp)) {
    printf("At line: %d\n", line_count);
    line_count += 1;
  }
  printf("Found %d lines\n", line_count);

  return 0;
}
