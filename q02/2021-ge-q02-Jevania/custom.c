// NIM - Name
// NIM - Name

#include "academic.h"
#include "custom.h"

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

int index_student(struct student_t *_students, unsigned short int _student_size, char *_id){ 
    int n; 
    for(n=0; n<_student_size; n++){
        if(strcmp(_students[n].id, _id) == 0){
            return n;
        }
    }
    return -1;
}

struct enrollment_t find_enrollment_by_code_and_id(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollment,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade, char *_code, char *_id);
  struct enrollment_t emt;
  strcpy(emt.grade, "GRADE_NONE");
  for(int n=0; n<_enrollment_size; n++){
      if(strcmp(_code, _courses[n].code) == 0 && strcmp(_id, _students[n].id)==0)){
          emt =  create_enrollment(_courses[n].code, _courses[n].name, _courses[n].credit, _courses[n].passing_grade);
          break;
      }
    }
  return crs;
}

