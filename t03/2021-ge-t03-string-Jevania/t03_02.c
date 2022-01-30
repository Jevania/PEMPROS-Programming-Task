// 12S20048 - Jevania

#include <stdio.h>
#include <string.h>
#define MAX 60

int main(int _argv, char **_argc) {
    
    char nChar[MAX];
    scanf("%[^\n]s", nChar);
   
    int i, stop = strlen(nChar);
    
    char allChar[1000];
    
    for(i=0; i<stop; i++){
       sprintf(allChar, "%03d", nChar[i]);
       printf("%s", allChar);
    }
    
    nChar[strlen(nChar)] = '\0';
    
    printf("\n");
    
    return 0;
}





