#ifndef CATALOG_H
#define CATALOG_H

#include <stdlib.h>

typedef struct _Course
{
  char div[3];
  int dept;
  int course_num;
  float credits;
  char title[34];
} Course;

// Course * Create_Course(char div[], int dept, int course_num, float credits, char title[]);
void get_course_parts(Course * u, char course_line[], char title[]);
Course * Create_Course(char course_line[]);
void print_course_info(Course * u);

#endif // CATALOG defined
