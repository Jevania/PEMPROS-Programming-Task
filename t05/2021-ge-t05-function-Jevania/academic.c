// 12S20007 - Rufina 
// 12S20048 - Jevania 

#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *grade_to_text(enum grade_t _grade) { 

  char *text = malloc(8);
  text[0] = '\0';

  switch(_grade){
    case GRADE_A : strcpy(text, "A");
      break;
    case GRADE_AB : strcpy(text, "AB");
      break;
    case GRADE_B : strcpy(text, "B");
      break;
    case GRADE_BC : strcpy(text, "BC");
      break;
    case GRADE_C : strcpy(text, "C");
      break;
    case GRADE_D : strcpy(text, "D");
      break;
    case GRADE_E : strcpy(text, "E");
      break;
    case GRADE_T : strcpy(text, "T");
      break;
    default : strcpy(text, "None");
  }
  
  return text; 
}


float calculate_performance(enum grade_t _grade, unsigned short _credit) {
  switch (_grade)
  {
    case GRADE_A: return 4.00 * _credit;
    case GRADE_AB:  return 3.50 * _credit;
    case GRADE_B: return 3.00 * _credit;
    case GRADE_BC: return 2.50 * _credit;
    case GRADE_C: return 2.00 * _credit;
    case GRADE_D: return 1.00 * _credit;
    case GRADE_E: return 0.00 ;
    case GRADE_T: return 0.00 ;
    default: return 0.00;
  }
}

//12S1102|Visual Programming|2|D
void print_course(struct course_t _course) {
  printf("%s|%s|%hi|%s\n", _course.code, _course.name, _course.credit, grade_to_text(_course.passing_grade));
}

//12S20999|Wiro Sableng|2020|Information Systems
void print_student(struct student_t _student) {
  printf("%s|%s|%s|%s\n", _student.id, _student.name, _student.year, _student.study_program);
}

//12S1102|12S20999|A|8.00
void print_enrollment(struct enrollment_t _enrollment) {
  printf("%s|%s|%s|%.2f\n", _enrollment.course.code, _enrollment.student.id, grade_to_text(_enrollment.grade), 
  calculate_performance(_enrollment.grade, _enrollment.course.credit));
}

struct course_t create_course(char *_code, char *_name, unsigned short _credit,
                              enum grade_t _passing_grade) {
  struct course_t crs;

  strcpy(crs.code, _code);
  strcpy(crs.name, _name);
  crs.credit = _credit;
  crs.passing_grade = _passing_grade;

  return crs;
}

struct student_t create_student(char *_id, char *_name, char *_year,
                                char *_study_program) {
  struct student_t std;

  strcpy(std.id, _id);
  strcpy(std.name, _name);
  strcpy(std.year, _year);
  strcpy(std.study_program, _study_program);

  return std;
}

struct enrollment_t create_enrollment(struct course_t _course,
                                      struct student_t _student, char *_year,
                                      enum semester_t _semester) {
  struct enrollment_t emt;

  strcpy(emt.course.code, _course.code);
  emt.course.credit = _course.credit;
  strcpy(emt.student.id, _student.id);
  strcpy(emt.year, _year);
  emt.semester = _semester;
  
  return emt;
}