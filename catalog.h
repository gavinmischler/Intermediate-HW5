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

Course * Create(char div, int dept, int course_num, float credits, char title[]);


#endif // CATALOG defined
