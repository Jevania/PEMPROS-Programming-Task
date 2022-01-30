#include "academic.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 100

int main(int _argc, char **_argv) {
    
    struct data_t{
        char input[MAX_INPUT];
    };

    struct data_t inputs[5];
    int nInput = 0;
    strcpy(inputs[nInput++].input, "create-student#12S20999#Wiro Sableng#2020#Information Systems");
    strcpy(inputs[nInput++].input, "print-students");
    strcpy(inputs[nInput++].input, "create-student#12S20998#Jaka Sembung#2020#Information Systems");
    strcpy(inputs[nInput++].input, "print-students");
    strcpy(inputs[nInput++].input, "---");

    unsigned short int nStudent = 0;
    struct student_t *stds = malloc((nStudent + 1) * sizeof(struct student_t)); 
    struct student_t std; 

    for(int i=0; i<nInput; i++){
        if(strcmp(inputs[i].input, "print-students") == 0){
            print_students(stds, nInput);
        }else if(strcmp(inputs[i].input, "---") == 0){
            break;
        }else{
            char tempData[MAX_INPUT];
            strcpy(tempData, inputs[i].input);
            char *token = strtok(tempData, "#");
            
            if(strcmp(token, "create-student") == 0){
                token = strtok(NULL, "#");
                strcpy(std.id, token);
                token = strtok(NULL, "#");
                strcpy(std.name, token);
                token = strtok(NULL, "#");
                strcpy(std.year, token);
                token = strtok(NULL, "#");
                strcpy(std.study_program, token);
                stds[nStudent] = create_student(std.id, std.name, std.year, std.study_program);
                nStudent += 1;
                stds = realloc(stds, (nStudent + 1) * sizeof(struct student_t));
            }
        }
    }

    free(stds);

  return 0;
}
