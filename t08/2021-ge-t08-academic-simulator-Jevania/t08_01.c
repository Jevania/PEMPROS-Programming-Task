// 12s20048 - Jevania

#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int _argc, char **_argv) {
  char *kata;
  char input[100];

  unsigned short int nStudents = 0;
  struct student_t *dataStudents = malloc((nStudents + 1) * sizeof(struct student_t)); 
  struct student_t tempStudent; 

  unsigned short int nCourses = 0;
  struct course_t *dataCourses = malloc((nCourses + 1) * sizeof(struct course_t)); 
  struct course_t tempCourse; 
  
  unsigned short int nEnrollments = 0;
  struct enrollment_t *dataEnrollments = malloc((nEnrollments + 1) * sizeof(struct enrollment_t)); 
  char tempYear[20];

  while(1==1){
    fgets(input, 100, stdin);
    input[strlen(input) - 1] = 0;

    if(strcmp(input, "---") == 0){
      break;
    }else if(strcmp(input, "print-students") == 0){
      print_students(dataStudents, nStudents);
    }else if(strcmp(input, "print-courses") == 0){
      print_courses(dataCourses, nCourses);
    }else if(strcmp(input, "print-enrollments") == 0){
      print_enrollments(dataEnrollments, nEnrollments);
    }else{
      char temp[100];
      strcpy(temp, input); 
      kata = strtok(temp, "#"); //kata#12S20999#Wiro Sableng#2020#Information Systems

      if(strcmp(kata, "create-student") == 0){
        kata = strtok(NULL, "#");
          strcpy(tempStudent.id, kata);
        kata = strtok(NULL, "#");
          strcpy(tempStudent.name, kata);
        kata = strtok(NULL, "#");
          strcpy(tempStudent.year, kata);
        kata = strtok(NULL, "#");
          strcpy(tempStudent.study_program, kata);
        
        dataStudents[nStudents] = create_student(tempStudent.id, tempStudent.name, tempStudent.year, tempStudent.study_program);
        nStudents = nStudents + 1;
        dataStudents = realloc(dataStudents, (nStudents + 1) * sizeof(struct student_t));

      }else if(strcmp(kata, "create-course") == 0){
        kata = strtok(NULL, "#");
          strcpy(tempCourse.code, kata);
        kata = strtok(NULL, "#");
          strcpy(tempCourse.name, kata);
        kata = strtok(NULL, "#");
          tempCourse.credit = atoi(kata);
        kata = strtok(NULL, "#");
          tempCourse.passing_grade = gradeEnum(kata);
        
        dataCourses[nCourses] = create_course(tempCourse.code, tempCourse.name, tempCourse.credit, tempCourse.passing_grade);
        nCourses = nCourses + 1;
        dataCourses = realloc(dataCourses, (nCourses + 1) * sizeof(struct course_t));

      }else if(strcmp(kata, "create-enrollment") == 0){
        kata = strtok(NULL, "#");
          tempCourse = find_course_by_code(dataCourses, nCourses, kata);
        kata = strtok(NULL, "#");
          tempStudent = find_student_by_id(dataStudents, nStudents, kata);
        kata = strtok(NULL, "#");
          strcpy(tempYear, kata);
        kata = strtok(NULL, "#");
          enum semester_t tempSemester = semesterEnum(kata);

        dataEnrollments[nEnrollments] = create_enrollment(tempCourse, tempStudent, tempYear, tempSemester);
        nEnrollments = nEnrollments + 1;
        dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));
      }
    }
  }
  return 0;
}