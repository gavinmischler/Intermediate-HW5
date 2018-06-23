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

int main(int argc, char const *argv[]) {

  char *filepath;
  if (argc == 2) {
    filepath = malloc(strlen(argv[1]+1));
    strcpy(filepath, argv[1]);
  } else {
    printf("Error: Not the right number of input arguments.\n");
    return -1;
  }

  FILE *fp = fopen(filepath, "r");
  if (fp == NULL) {
    printf("Error: input file not opened\n");
    free(filepath);
    return -1;
  }

  int line_count = 0;
  char line[50];
  while (fgets(line, 50, fp)) {
    printf("At line: %d\n", line_count);
    line_count += 1;
  }
  fclose(fp);
  //printf("Found %d lines\n", line_count);

  fp = fopen(filepath, "r");
  Course * catalog[line_count];

  // while (fgets(line, 50, fp)) {
  //   printf("line= %s\n", line);
  // }
    fclose(fp);
  // for (int i = 0; i < line_count; i++) {
  //   catalog[i] = Create_Course();
  //
  // }
  char test_course_line[] = "EN.300.30 3.2 test course line";
  Course *test_course = Create_Course(test_course_line);
  print_course_info(test_course);

  return 0;
}
