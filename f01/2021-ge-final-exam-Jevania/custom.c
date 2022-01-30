// 12S20048 - Jevania
// 12S20050 - Putri Esrahana

#include "custom.h"
#include "transaction.h"
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



