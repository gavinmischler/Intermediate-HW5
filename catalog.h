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
void get_course_parts(Course * u, char course_line[], unsigned int line_length);
Course * Create_Course(char course_line[], unsigned int line_length);
void print_course_info(Course * u);
int is_valid_course(char course_id[], unsigned long id_length);
void get_course_input(char user_menu_input[]);
void separate_course_parts(char course_id[], char div[], int * dept, int * course_num);
int find_course_in_catalog(Course * catalog[], int catalog_sz, char div[], int *dept, int *course_num);

#endif // CATALOG defined
