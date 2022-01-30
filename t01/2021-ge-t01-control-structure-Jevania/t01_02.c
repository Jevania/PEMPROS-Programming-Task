#include <stdio.h>

int main(int _argv, char **_argc) {

   int ucok;
   int butet;
   scanf("%d", &ucok);
   scanf("%d", &butet);
   
   int nUcok = (ucok+2-1) / 2;
   int nButet = (butet+2-1) / 2;;
   
   int TimeUcok = 0;
   int TimeButet = 0;
   
   if(nButet != 0 && nUcok != 0){
    TimeUcok += 3;
   }

   if(nButet < nUcok){
    do{
      TimeUcok +=3;
      if(nButet > 0){
        TimeButet += 3;
        TimeUcok += 3;
        nButet = nButet - 1;
      }
      nUcok = nUcok - 1;
    }while(nUcok > 0);
  }else{
    while(nButet > 0){
        TimeButet += 3;
        if(nUcok > 0){
            TimeUcok += 3;
            TimeButet += 3;
            nUcok = nUcok - 1;
        }
        nButet = nButet - 1;
    }
  }

  printf("%d\n", TimeUcok);
  printf("%d\n", TimeButet);
  printf("%d\n", TimeUcok + TimeButet);
  
  return 0;
  }