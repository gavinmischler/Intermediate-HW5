#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "catalog.h"

// Gets the division different components from the entire course line and puts them
// in pointers or arrays
void get_course_parts(Course * u, char course_line[], unsigned int line_length) {
  char credits_str[4];
  char title[34];
  int pos;
  for (pos = 0; pos < 3; pos++) {
    credits_str[pos] = course_line[11+pos];
    if (course_line[11+pos] == '.') {
    }
  }
  credits_str[pos] = '\0';
  u->credits = atof(credits_str);

  int num_title_chars = line_length - 15;
  for (pos = 0; pos < num_title_chars; pos++) {
    title[pos] = course_line[15+pos];
  }
  title[pos] = '\0';
  strcpy((u->title), title);

  char * token;
  char delim[2] = ".";
  token = strtok(course_line, delim);
  int num_toks = 1;
  while (num_toks < 4 && token != NULL) {
    if (num_toks == 1) {
      strcpy((u->div), token);
      token = strtok(NULL, delim);
    } else if (num_toks == 2) {
      u->dept = atoi(token);
      token = strtok(NULL, delim);
    } else if (num_toks == 3) {
      u->course_num = atoi(token);
      token = strtok(NULL, delim);
    }
    num_toks += 1;
  }

}

// Creates a pointer to a Course data type which is a struct containing all the components
// of the course from the catalog
Course * Create_Course(char course_line[], unsigned int line_length) {
  Course * u = malloc(sizeof(Course));
  assert(u);
//

  // *dept = 1;
  // *course_num = 111;
  // *credits = 1.1;
  get_course_parts(u, course_line, line_length);
//

  // strcpy((u->div), div);
  // u->dept = *dept;
  // u->course_num = *course_num;

  return u;
}

void print_course_info(Course * u) {
  printf("%s.%d.%d %.1f %s\n", u->div, u->dept, u->course_num, u->credits, u->title);
}
