// 12S20007 - Rufina
// 12S20048 - Jevania

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct penilaian{
	char nama[50];
	int bobot;
    int nilai;
};

int main(int _argv, char **_argc) {
    int k ;
    int i ; 

    k = atoi(_argc[1]);

    struct penilaian S[k];
    char allInput[100];
    
    if(k > 0 && k <= 5){
        for(i=0; i<k; i++){
            fgets(allInput, 50, stdin);
            allInput[strcspn(allInput, "\r\n")] = 0;

            char* value;        
            value = strtok(allInput, "#");
            if(value != NULL) strcpy(S[i].nama, value);

            value = strtok(NULL, "#");
            if(value != NULL) S[i].bobot = atoi(value);
            
            value = strtok(NULL, "#");
            if(value != NULL) S[i].nilai = atoi(value);
        }

         float nAkhir[k];
         float kesimpulan=0;

        for(i=0; i<k; i++){
            printf("%s;%d;%d\n", S[i].nama, S[i].bobot, S[i].nilai);
        }

        for(i=0; i<k; i++){
            nAkhir[i] = ((S[i].bobot/100.00) * S[i].nilai);
            kesimpulan = kesimpulan + nAkhir[i];
        }
        
        printf("%.1f\n", kesimpulan);

        if(kesimpulan>=50){
            printf("passed\n");
        }else if(kesimpulan<50){
            printf("failed\n");
        }
    }

  return 0;
}
