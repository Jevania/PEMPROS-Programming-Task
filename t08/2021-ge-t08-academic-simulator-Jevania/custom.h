
// 12s20048 - Jevania

#include "academic.h"

#ifndef CUSTOM_H
#define CUSTOM_H

enum grade_t gradeEnum(char *grade);
enum semester_t semesterEnum(char *semester);
int index_student(struct student_t *_students, unsigned short int _student_size, char *_id);

#endif
