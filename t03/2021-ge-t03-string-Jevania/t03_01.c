// 12S20048 - Jevania

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 60

int main(int _argv, char **_argc) {
    
    char nWord[MAX];
    scanf("%s", nWord);

    int i, allWord = strlen(nWord);
    for(i=0; i<allWord; i += 3){
        char data[4];
        data[0] = nWord[i];
        data[1] = nWord[i+1];
        data[2] = nWord[i+2];
        data[3] = '\0';
        
        printf("%c", atoi(data));
    }
    printf( "\n");

return 0;
}


