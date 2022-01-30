// 12S20048 - Jevania

#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_input(char *_buffer, unsigned int _size){
    char input ='\0';
    unsigned int i=0;
    _buffer[i] = '\0';

    while(i<_size && (input = getchar()) != EOF){
        if(input == '\r'){
            continue;
        }
        if(input == '\n'){
            break;
        }
        _buffer[i++] = input;
        _buffer[i] = '\0';
    }
}

enum semester_t semesterEnum(char *semester){
    if(strcmp(semester, "odd") == 0){
        return SEMESTER_ODD;
    }else if(strcmp(semester, "even") == 0){
        return SEMESTER_EVEN;
    }else{
        return SEMESTER_SHORT;
    }
}

enum grade_t gradeEnum(char *grade){
    if(strcmp(grade, "A") == 0){
        return GRADE_A;
    }else if(strcmp(grade, "AB") == 0){
        return GRADE_AB;
    }else if(strcmp(grade, "B") == 0){
        return GRADE_B;
    }else if(strcmp(grade, "BC") == 0){
        return GRADE_BC;
    }else if(strcmp(grade, "C") == 0){
        return GRADE_C;
    }else if(strcmp(grade, "D") == 0){
        return GRADE_D;
    }else if(strcmp(grade, "E") == 0){
        return GRADE_E;
    }else if(strcmp(grade, "T") == 0){
        return GRADE_T;
    }else{
        return GRADE_NONE;
    }
}

struct enrollment_t find_enrollment_by_code_and_id(struct enrollment_t *_enrollments, unsigned short int _enrollment_size,
                                                     char *_course_code, char *_student_id){
  struct enrollment_t emt;
  strcpy(emt.student.id, "None");
  for(int n=0; n<_enrollment_size; n++){
    if(strcmp(_course_code, _enrollments[n].course.code)==0 && strcmp(_student_id, _enrollments[n].student.id)==0){
        strcpy(emt.course.code, _enrollments[n].course.code);
        strcpy(emt.student.id, _enrollments[n].student.id);
        break;
    }
  }
  return emt;
}
  

