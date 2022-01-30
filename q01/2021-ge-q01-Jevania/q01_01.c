// 12S20048 - Jevania

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct data{
	char nama[50];
	int nilai;
    char tipe[50];
};

int main(int _argv, char **_argc) {
    int t;
    int i, n=0;
    int nIncome=0, nExpense=0;

    t = atoi(_argc[1]);

    struct data nData[t];
    char lines[100];
    
    if(t > 0 && t <= 100){
        for(i=0; i<t; i++){
            fgets(lines, 50, stdin);
            lines[strcspn(lines, "\r\n")] = 0;
          
            char* myVal;
            myVal = strtok(lines, "#");
            if(myVal != NULL) strcpy(nData[i].tipe, myVal);

            myVal = strtok(NULL, "#");
            if(myVal != NULL) nData[i].nilai = atoi(myVal);
            
            myVal = strtok(NULL, "#");
            if(myVal != NULL) strcpy(nData[i].nama, myVal);
        }

        for(i=0; i<t; i++){
            if(strcmp(nData[i].tipe, "income") == 0){
                printf("%s;%d;%s\n", nData[i].nama, nData[i].nilai, nData[i].tipe);
                nIncome = nIncome + nData[i].nilai;
        }
        }

        for(i=0; i<t; i++){
            if(strcmp(nData[i].tipe, "expense") == 0){
                printf("%s;%d;%s\n", nData[i].nama, nData[i].nilai, nData[i].tipe);
                nExpense = nExpense + nData[i].nilai;
        }
        }

        printf("%d %d\n", nIncome, nExpense);

        if(nIncome>nExpense){
            printf("surplus\n");
        }else if(nIncome<nExpense){
            printf("deficit\n");
        }else{
            printf("balanced\n");
        }
    
    }

  return 0;
}
