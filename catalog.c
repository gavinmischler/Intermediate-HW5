#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "catalog.h"
#include "prompts.h"



// Gets the different components from the entire course line and puts them
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

// Finds the location of a course in the catalog based on div, dept, and course_num
/*
  Returns: the index of the course in the array, or -1 if not found
*/
int find_course_in_catalog(Course * catalog[], int catalog_sz, char div[], int *dept, int *course_num) {
  int i;
  for (i = 0; i < catalog_sz; i++) {
    if (!strcmp(((catalog[i])->div), div) && (catalog[i]->dept == *dept) && (catalog[i]->course_num == *course_num)) {
      return i;
    }
  }
  return -1;
}

// Takes in a string course ID and puts the 3 components into pointers
/*
  Inputs:
    char course_id[]; this is a 10 character valid course ID
*/
void separate_course_parts(char course_id[], char divi[], int * dept, int * course_num) {
  char * token;
  char delim[2] = ".";
  token = strtok(course_id, delim);
  int num_toks = 1;
  while (num_toks < 4 && token != NULL) {
    if (num_toks == 1) {
      strcpy(divi, token);
      token = strtok(NULL, delim);
    } else if (num_toks == 2) {
      *dept = atoi(token);
      token = strtok(NULL, delim);
    } else if (num_toks == 3) {
      *course_num = atoi(token);
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
  get_course_parts(u, course_line, line_length);

  // strcpy((u->div), div);
  // u->dept = *dept;
  // u->course_num = *course_num;

  return u;
}

// Checks if the user has input a valid course ID
/*
  Returns: 1 if valid, 0 if invalid
*/
int is_valid_course(char course_id[], unsigned long id_length) {
  if (id_length != 10) {
    invalid_input_msg();
    return 0;
  }
  for (unsigned long j = 0; j < id_length; j++) {
    char temp_char = course_id[j];
    if (temp_char == '.' && (j != 2 && j != 6)) {
      invalid_input_msg();
      return 0;
    } else if ((j == 2 || j == 6) && temp_char != '.') {
      invalid_input_msg();
      return 0;
    }
  }
  return 1;
}

// Repeatedly asks the user for a course id until they provide a valid one
void get_course_input(char user_menu_input[]) {
  do {
    course_prompt();
    scanf("%s", user_menu_input);
  } while(!(is_valid_course(user_menu_input, strlen(user_menu_input))));
}

void print_course_info(Course * u) {
  printf("%s.%d.%d %.1f %s", u->div, u->dept, u->course_num, u->credits, u->title);
}

void get_title(char user_menu_input[]) {
  fgetc(stdin);
  new_title_prompt();
  fgets(user_menu_input, 100, stdin);
  while (strlen(user_menu_input) > 32) {
    invalid_input_msg();
    new_title_prompt();
    fgets(user_menu_input, 100, stdin);
  }
}

float get_credits(char user_menu_input[]) {
  fgetc(stdin);
  float new_credits;
  new_credit_prompt();
  fgets(user_menu_input, 100, stdin);
  while (!sscanf(user_menu_input, "%f", &new_credits) || user_menu_input[0] == '\n') {
    new_credit_prompt();
    fgets(user_menu_input, 100, stdin);
  }
  return new_credits;
}

void set_title(Course * u, char new_title[]) {
  strcpy(u->title, new_title);
}

void set_credits(Course * u, float new_credits) {
  u->credits = new_credits;
}
