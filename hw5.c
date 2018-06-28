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
    line_count += 1;
  }
  fclose(fp);
  //printf("Found %d lines\n", line_count);

  fp = fopen(filepath, "r");
  Course * catalog[line_count];
  int c = 0;
  while (fgets(line, 50, fp)) {
    unsigned int line_length = sizeof(line)/sizeof(char);
    catalog[c] = Create_Course(line, line_length);
    c++;
  }
  printf("added %d courses to catalog\n", c);
  fclose(fp);

  char menu_selection = 'a';
  char user_menu_input[30];

  menu_prompt();
  scanf("%s", user_menu_input);
  menu_selection = user_menu_input[0];
  while (menu_selection != 'q') {
    switch (menu_selection) {
      case '1': // Display the catalog
        for (int j = 0; j < line_count; j++) {
          print_course_info(catalog[j]);
        }
        break;
      case '2':
        get_course_input(user_menu_input);
        char div[3];
        int temp = 0, *dept = &temp;
        int temp2 = 0, *course_num = &temp2;
        separate_course_parts(user_menu_input, div, dept, course_num);
        int idx = find_course_in_catalog(catalog, line_count, div, dept, course_num);
        print_course_info(catalog[idx]);
        break;

    }


    menu_prompt();
    scanf("%s", user_menu_input);
    menu_selection = user_menu_input[0];

  }

  return 0;
}
