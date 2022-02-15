// 12S20048 - Jevania

#include "academic.h"

#ifndef CUSTOM_H
#define CUSTOM_H

void get_input(char *_buffer, unsigned int _size);
enum grade_t gradeEnum(char *grade);
enum semester_t semesterEnum(char *semester);
struct enrollment_t find_enrollment_by_code_and_id(struct enrollment_t *_enrollments, unsigned short int _enrollment_size,
                                                     char *_course_code, char *_student_id);

#endif
