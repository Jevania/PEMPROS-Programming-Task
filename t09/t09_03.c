// 12S20048 - Jevania

#include "academic.h"
#include "custom.h"
#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//? gcc t09_03.c academic.c custom.c repository.c -o t09_03

int main(int _argc, char **_argv) {
  char *kata;
  char input[100];

  unsigned short int nStudents = 0;
  struct student_t *dataStudents = malloc((nStudents + 1) * sizeof(struct student_t)); 
  struct student_t tempStudent; 
  struct student_t pastStudent;

  unsigned short int nCourses = 0;
  struct course_t *dataCourses = malloc((nCourses + 1) * sizeof(struct course_t)); 
  struct course_t tempCourse; 
  struct course_t pastCourse;
  
  unsigned short int nEnrollments = 0;
  struct enrollment_t *dataEnrollments = malloc((nEnrollments + 1) * sizeof(struct enrollment_t)); 
  char tempYear[25];
  struct enrollment_t pastEnrollment;

  char temp[100];
  FILE *fptr1;
  fptr1 = fopen("./storage/student-repository.txt", "r");

    while (fgets(input, 100, fptr1) != NULL)
      {
        strcpy(temp, input);                    //input = kata|kata|kata|kata|kata
        kata = strtok(temp, "|");
    
        strcpy(dataStudents[nStudents].id, kata);
        kata = strtok(NULL, "|");
        strcpy(dataStudents[nStudents].name, kata);
        kata = strtok(NULL, "|");
        strcpy(dataStudents[nStudents].year, kata);
        kata = strtok(NULL, "|");
        strcpy(dataStudents[nStudents].study_program, kata);
        kata = strtok(NULL, "|");
        dataStudents[nStudents].gpa = atof(kata);
    
        nStudents += 1;
        dataStudents = realloc(dataStudents, (nStudents + 1) * sizeof(struct student_t));
      }
    fclose(fptr1);

  FILE *fptr2;
  fptr2 = fopen("./storage/course-repository.txt", "r");
    while (fgets(input, 100, fptr2) != NULL)
      {
        strcpy(temp, input);          //input = kata|kata|kata|kata|kata
        kata = strtok(temp, "|");

        kata = strtok(NULL, "|");
        strcpy(dataCourses[nCourses].code, kata);
        kata = strtok(NULL, "|");
        strcpy(dataCourses[nCourses].name, kata);
        kata = strtok(NULL, "|");
        dataCourses[nCourses].credit = atoi(kata);
        kata = strtok(NULL, "|");
        dataCourses[nCourses].passing_grade = gradeEnum(kata);
    
        nCourses += 1;
        dataCourses = realloc(dataCourses, (nCourses + 1) * sizeof(struct course_t));
      }
    fclose(fptr2);

  FILE *fptr3;
  fptr3 = fopen("./storage/student-repository.txt","r");
   while(fgets(input, 100, fptr3) != NULL)
      {
        strcpy(temp, input);                                 //input = kata|kata|kata|kata|kata
        kata = strtok(NULL, "|");

        tempCourse = find_course_by_code(dataCourses, nCourses, kata);
        kata = strtok(NULL, "|");
        tempStudent = find_student_by_id(dataStudents, nStudents, kata);
        kata = strtok(NULL, "|");
        strcpy(tempYear, kata);
        kata = strtok(NULL, "|");
        enum semester_t temp_semester = semesterEnum(kata);

        dataEnrollments[nEnrollments] = create_enrollment(tempCourse, tempStudent, tempYear, temp_semester);
        dataEnrollments[nEnrollments].grade = gradeEnum(kata);
        nEnrollments += 1;
        dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));
      }
    fclose(fptr3);

  while(1==1){
    get_input(input, 100);

    if(strcmp(input, "---") == 0){
      break;
    }else if(strcmp(input, "print-students") == 0){
      print_students(dataStudents, nStudents);
    }else if(strcmp(input, "print-courses") == 0){
      print_courses(dataCourses, nCourses);
    }else if(strcmp(input, "print-enrollments") == 0){
      print_enrollments(dataEnrollments, nEnrollments);
    }

    else{
      strcpy(temp, input); 
      kata = strtok(temp, "#");

      if(strcmp(kata, "create-student") == 0){
        kata = strtok(NULL, "#");
        strcpy(tempStudent.id, kata);
        kata = strtok(NULL, "#");
        strcpy(tempStudent.name, kata);
        kata = strtok(NULL, "#");
        strcpy(tempStudent.year, kata);
        kata = strtok(NULL, "#");
        strcpy(tempStudent.study_program, kata);

          pastStudent = find_student_by_id(dataStudents, nStudents, tempStudent.id);
        
        if(!(strcmp(tempStudent.id, pastStudent.id)==0)){
          dataStudents[nStudents] = create_student(tempStudent.id, tempStudent.name, tempStudent.year, tempStudent.study_program);
          nStudents = nStudents + 1;
          dataStudents = realloc(dataStudents, (nStudents + 1) * sizeof(struct student_t));
        }
        
      }else if(strcmp(kata, "create-course") == 0){
        kata = strtok(NULL, "#");
        strcpy(tempCourse.code, kata);
        kata = strtok(NULL, "#");
        strcpy(tempCourse.name, kata);
        kata = strtok(NULL, "#");
        tempCourse.credit = atoi(kata);
        kata = strtok(NULL, "#");
        tempCourse.passing_grade = gradeEnum(kata);

        pastCourse = find_course_by_code(dataCourses, nCourses, tempCourse.code);

        if(!(strcmp(tempCourse.code, pastCourse.code)==0)){
          dataCourses[nCourses] = create_course(tempCourse.code, tempCourse.name, tempCourse.credit, tempCourse.passing_grade);
          nCourses = nCourses + 1;
          dataCourses = realloc(dataCourses, (nCourses + 1) * sizeof(struct course_t));
        }

      }else if(strcmp(kata, "create-enrollment") == 0){
        kata = strtok(NULL, "#");
        tempCourse = find_course_by_code(dataCourses, nCourses, kata);
        kata = strtok(NULL, "#");
        tempStudent = find_student_by_id(dataStudents, nStudents, kata);
        kata = strtok(NULL, "#");
        strcpy(tempYear, kata);
        kata = strtok(NULL, "#");
        enum semester_t tempSemester = semesterEnum(kata);

          pastEnrollment = find_enrollment_by_code_and_id(dataEnrollments, nEnrollments, tempStudent.id, tempCourse.code);

          if(strcmp(tempStudent.id, "None")==0){
            dataEnrollments[nEnrollments] = create_enrollment(tempCourse, tempStudent, tempYear, tempSemester);
            nEnrollments = nEnrollments + 1;
            dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));
          } 
      }
    }
  }

  save_students_to_repository(dataStudents, nStudents);
  save_courses_to_repository(dataCourses, nCourses);
  save_enrollments_to_repository(dataEnrollments, nEnrollments);
  
  return 0;
}