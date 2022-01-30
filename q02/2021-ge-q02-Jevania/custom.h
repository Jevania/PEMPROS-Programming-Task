// NIM - Name
// NIM - Name

#include "academic.h"

#ifndef CUSTOM_H
#define CUSTOM_H

enum grade_t gradeEnum(char *grade);
enum semester_t semesterEnum(char *semester);
int index_student(struct student_t *_students, unsigned short int _student_size, char *_id);
struct enrollment_t find_enrollment_by_code_and_id(struct course_t _course, struct student_t _student,
                          struct enrollment_t *_enrollment,
                          unsigned short int _enrollment_size,
                          enum grade_t _grade, char *_code, char *_id);

#endif
