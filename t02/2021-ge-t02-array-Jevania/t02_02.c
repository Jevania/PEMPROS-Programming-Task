// 12S2007 - Rufina
// 12S20048 - Jevania

#include<stdio.h>

int main(){

    int n, i, even = 0, arLong;
    scanf("%d", &n);
    
    even = (n % 2 == 0);
    int number[n];

    for(i=0;i<n;i++){
        scanf("%d", &number[i]);
    }

    for(i=0;i<n;i++){
        if(i == n - 1){
         printf("%d\n", number[i]);
        }else{
         printf("%d,", number[i]);
        }
    }

    arLong = n / 2;

    for(i=0;i<arLong;i++){
        printf("%d,%d", number[i], number[n - 1 - i]);
        if(i == arLong - 1){
            if(even){
                printf("\n");
            }else{
                printf(",");
            }
        }else{
            printf(",");
        }
    }
    if(!even){
        printf("%d\n", number[arLong]);
    }


    return 0;
}