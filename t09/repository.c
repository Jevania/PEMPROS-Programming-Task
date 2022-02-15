// 12S20048 - Jevania

#include "repository.h"
#include "academic.h"
#include "custom.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! notes : Shift + Alt + F  --> merapikan code

short int load_students_from_repository(struct student_t **_students)
{
  return 0;
}

short int load_courses_from_repository(struct course_t **_courses)
{
  return 0;
}

short int load_enrollments_from_repository(struct enrollment_t **_enrollments,
                                           struct course_t *_courses,
                                           unsigned short int _course_size,
                                           struct student_t *_students,
                                           unsigned short int _student_size)
{
  return 0;
}

void save_courses_to_repository(struct course_t *_courses,
                                unsigned short int _course_size)
{
  FILE *repositoryCrs = fopen(DEFAULT_COURSE_REPOSITORY, "w");
  if (repositoryCrs == NULL)
  {
    printf("Something went wrong\n");
    return;
  }

  int n;
  for (n = 0; n < _course_size; n++)
  {
    fprintf(repositoryCrs, "%s|%s|%hi|%s\n", _courses[n].code, _courses[n].name, _courses[n].credit,
            grade_to_text(_courses[n].passing_grade));
  }

  fflush(repositoryCrs);

  short int errorCrs = fclose(repositoryCrs);
  if (errorCrs != 0)
  {
    printf("Something went wrong\n");
    return;
  }
}

void save_students_to_repository(struct student_t *_students,
                                 unsigned short int _student_size)
{
  FILE *repositoryStd = fopen(DEFAULT_STUDENT_REPOSITORY, "w");
  if (repositoryStd == NULL)
  {
    printf("Something went wrong\n");
    return;
  }

  int n;
  for (n = 0; n < _student_size; n++)
  {
    fprintf(repositoryStd, "%s|%s|%s|%s|%.2f\n", _students[n].id,
             _students[n].name, _students[n].year, _students[n].study_program,
             _students[n].gpa);
  }

  fflush(repositoryStd);

  short int errorStd = fclose(repositoryStd);
  if (errorStd != 0)
  {
    printf("Something went wrong\n");
    return;
  }
}

void save_enrollments_to_repository(struct enrollment_t *_enrollments,
                                    unsigned short int _enrollment_size)
{
  FILE *repositoryEmt = fopen(DEFAULT_ENROLLMENT_REPOSITORY, "w");
  if (repositoryEmt == NULL)
  {
    printf("Something went wrong\n");
    return;
  }

  int n;
  for (n = 0; n < _enrollment_size; n++)
  {
    fprintf(repositoryEmt, "%s|%s|%s|%.2f\n", _enrollments[n].course.code, 
            _enrollments[n].student.id, grade_to_text(_enrollments[n].grade), 
            calculate_performance(_enrollments[n].grade, _enrollments[n].course.credit));
  }

  fflush(repositoryEmt);

  short int errorEmt = fclose(repositoryEmt);
  if (errorEmt != 0)
  {
    printf("Something went wrong\n");
    return;
  }
}
