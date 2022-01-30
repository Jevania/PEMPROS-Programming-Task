#include "academic.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_INPUT 100

int main(int _argc, char **_argv) {
  

  struct data_t{
        char input[MAX_INPUT];
    };

    struct data_t inputs[13];
    int nInput = 0;
    strcpy(inputs[nInput++].input, "create-student#12S20999#Wiro Sableng#2020#Information Systems");
    strcpy(inputs[nInput++].input, "print-students");
    strcpy(inputs[nInput++].input, "create-student#12S20998#Jaka Sembung#2020#Information Systems");
    strcpy(inputs[nInput++].input, "print-students");
    strcpy(inputs[nInput++].input, "create-course#12S1102#Visual Programming#2#D");
    strcpy(inputs[nInput++].input, "print-courses");
    strcpy(inputs[nInput++].input, "create-course#10S1002#Procedural Programming#2#C");
    strcpy(inputs[nInput++].input, "print-courses");
    strcpy(inputs[nInput++].input, "print-students");
    strcpy(inputs[nInput++].input, "find-student-by-id#12S20998");
    strcpy(inputs[nInput++].input, "print-courses");
    strcpy(inputs[nInput++].input, "find-student-by-id#12S20999");
    strcpy(inputs[nInput++].input, "---");

    unsigned short int nStudent = 0;
    struct student_t *_students = malloc((nStudent + 1) * sizeof(struct student_t)); // size = 1
    struct student_t _student; 

    unsigned short int nCourse = 0;
    struct course_t *_courses = malloc((nCourse + 1) * sizeof(struct course_t)); // size = 1
    struct course_t _course; 

    for(int i=0; i<nInput; i++){
        if(strcmp(inputs[i].input, "print-students") == 0){
            print_students(_students, nStudent);
        }else if(strcmp(inputs[i].input, "print-courses") == 0){
            print_courses(_courses, nCourse);
        }else if(strcmp(inputs[i].input, "---") == 0){
            break;
        }else{
            char tempData[MAi_INPUT];
            strcpy(tempData, inputs[i].input);
            char *token = strtok(tempData, "#");
            
            if(strcmp(token, "create-student") == 0){
                token = strtok(NULL, "#");
                strcpy(_student.id, token);
                token = strtok(NULL, "#");
                strcpy(_student.name, token);
                token = strtok(NULL, "#");
                strcpy(_student.year, token);
                token = strtok(NULL, "#");
                strcpy(_student.study_program, token);
                _students[nStudent] = create_student(_student.id, _student.name, _student.year, _student.study_program);
                nStudent += 1;
                _students = realloc(_students, (nStudent + 1) * sizeof(struct student_t));
            }else if(strcmp(token, "create-course") == 0){
                token = strtok(NULL, "#");
                strcpy(_course.code, token);
                token = strtok(NULL, "#");
                strcpy(_course.name, token);
                token = strtok(NULL, "#");
                _course.credit = atoi(token);
                token = strtok(NULL, "#");

                if(strcmp(token, "A") == 0){
                  _course.passing_grade = GRADE_A;
                }else if(strcmp(token, "AB") == 0){
                   _course.passing_grade = GRADE_AB;
                }else if(strcmp(token, "B") == 0){
                   _course.passing_grade = GRADE_B;
                }else if(strcmp(token, "BC") == 0){
                   _course.passing_grade = GRADE_BC;
                }else if(strcmp(token, "C") == 0){
                   _course.passing_grade = GRADE_C;
                }else if(strcmp(token, "D") == 0){
                   _course.passing_grade = GRADE_D;
                }else if(strcmp(token, "E") == 0){
                   _course.passing_grade = GRADE_E;
                }else if(strcmp(token, "T") == 0){
                   _course.passing_grade = GRADE_T;
                }else{
                   _course.passing_grade = GRADE_NONE;
                }

                _courses[nCourse] = create_course(_course.code, _course.name, _course.credit, _course.passing_grade);
                nCourse += 1;
                _courses = realloc(_courses, (nCourse + 1) * sizeof(struct course_t));
            
            }else if(strcmp(token, "find-student-by-id") == 0){
                token = strtok(NULL, "#");
                char temp[MAX_INPUT];
                strcpy(temp, token);
                print_student(find_student_by_id(_students, nStudent, temp));
        }
    }

    free(_students);
    free(_courses);

    return 0;

}
