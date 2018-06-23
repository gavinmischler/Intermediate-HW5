#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "catalog.h"

// Gets the division different components from the entire course line and puts them
// in pointers or arrays
void get_course_parts(Course * u, char course_line[], char title[]) {
  char * token;
  char delim[2] = ".";
  token = strtok(course_line, delim);
  int num_toks = 1;
  while (num_toks < 4 && token != NULL) {
    if (num_toks == 1) {
      strcpy((u->div), token);
    } else if (num_toks == 2) {
      u->dept = atoi(token);
    } else if (num_toks == 3) {
      u->course_num = atoi(token);
    }
    token = strtok(NULL, delim);
    num_toks += 1;
  }
  u->credits = 1.1;
  strcpy((u->title), title);
}

// Creates a pointer to a Course data type which is a struct containing all the components
// of the course from the catalog
Course * Create_Course(char course_line[]) {
  Course * u = malloc(sizeof(Course));
  assert(u);
//

  char title[] = "This is the title";
  // *dept = 1;
  // *course_num = 111;
  // *credits = 1.1;
  get_course_parts(u, course_line, title);
//

  // strcpy((u->div), div);
  // u->dept = *dept;
  // u->course_num = *course_num;

  return u;
}

void print_course_info(Course * u) {
  printf("%s.%d.%d %f %s\n", u->div, u->dept, u->course_num, u->credits, u->title);
}
