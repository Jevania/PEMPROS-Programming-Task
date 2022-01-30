// 12S20007 - Rufina
// 12s20048 - Jevania

#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 12S20048 - Jevania
// 12s20050 - Putri Esrahana

int main(int _argc, char **_argv) {
  char *kata;

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
  enum grade_t tempGrade;
  struct enrollment_t pastEnrollment;

  int nInput=0;

  while(1==1){

    for (nInput = 0; nInput < 100; nInput++){
        char word[100] = "";
        short int nWord = 0;
        word[0] = '\0';
        while (1){
          char input = '\0';
          input = getchar();
            if (input != '\r' && input != '\n'){
              word[nWord] = input;
              word[++nWord] = '\0';
            }else{
              if (input == '\r'){
                continue;
              }else if (input == '\n'){
                nWord = 100;
              };
          }  

    if(strcmp(word, "---") == 0){
      break;
    }else if(strcmp(word, "print-students") == 0){
      print_students(dataStudents, nStudents);
    }else if(strcmp(wordt, "print-courses") == 0){
      print_courses(dataCourses, nCourses);
    }else if(strcmp(word, "print-enrollments") == 0){
      print_enrollments(dataEnrollments, nEnrollments);
    }else{
      
      char temp[100];
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
        
        if(!strcmp(tempStudent.id, pastStudent.id) ==0){
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

        if(!strcmp(tempCourse.code, pastCourse.code)==0){
          dataCourses[nStudents] = create_course(tempCourse.code, tempCourse.name, tempCourse.credit, tempCourse.passing_grade);
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
          enum semester_t temp_semester = semesterEnum(kata);

        pastEnrollment = find_enrollment_by_code_and_id(dataCourses, dataStudents, dataEnrollments, 
                                                        nCourses, nEnrollments, tempCourse)

        if(!strcmp(tempCourse.code, pastCourse.code)==0 && !strcmp(tempStudent.id, pastStudent.id){
          dataEnrollments[nEnrollments] = create_Enrollment(dataCourses, dataStudents, tempYear, temp_semester);
          nEnrollments = nEnrollments + 1;
          dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));
        } 

        dataEnrollments[nEnrollments] = create_enrollment(tempCourse, tempStudent, tempYear, temp_semester);
        nEnrollments = nEnrollments + 1;
        dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));

      }else if(strcmp(kata, "set-enrollment-grade") == 0){
        kata = strtok(NULL, "#");
          tempCourse = find_course_by_code(dataCourses, nCourses, kata);
        kata = strtok(NULL, "#");
          tempStudent = find_student_by_id(dataStudents, nStudents, kata);
        kata = strtok(NULL, "#");
        kata = strtok(NULL, "#");
        kata = strtok(NULL, "#");
          tempGrade = gradeEnum(kata);

        pastEnrollment = find_enrollment_by_code_and_id(dataCourses, dataStudents, dataEnrollments, 
                                                        nCourses, nEnrollments, tempCourse)

        if(!strcmp(tempCourse.code, pastCourse.code)==0 && !strcmp(tempStudent.id, pastStudent.id){
          dataEnrollments[nEnrollments] = create_Enrollment(dataCourses, dataStudents, tempYear, temp_semester);
          nEnrollments = nEnrollments + 1;
          dataEnrollments = realloc(dataEnrollments, (nEnrollments + 1) * sizeof(struct enrollment_t));
        } 

        set_enrollment_grade(tempCourse, tempStudent, dataEnrollments, nEnrollments, tempGrade);
        int index = index_student(dataStudents, nStudents, tempStudent.id);
        calculate_gpa(&dataStudents[index], dataEnrollments, nEnrollments);
      }
      }
    }  
  }
  }
  return 0;
}
