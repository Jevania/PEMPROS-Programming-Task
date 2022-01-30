#include <stdio.h>

int main(int _argv, char **_argc) {
  
    int month, x1, x2, x3;

    scanf("%d", &month);
    month = month - 1;
    
    if(month == 0) printf("January\n");
    else if(month == 1) printf("February\n");
    else if(month == 2) printf("March\n");
    else if(month == 3) printf("April\n");
    else if(month == 4) printf("May\n");
    else if(month == 5) printf("June\n");
    else if(month == 6) printf("July\n");
    else if(month == 7) printf("August\n");
    else if(month == 8) printf("September\n");
    else if(month == 9) printf("October\n");
    else if(month == 10) printf("November\n");
    else if(month == 11) printf("December\n");
    
    month = (month+1) % 12;
    
    if(month == 0) printf("January\n");
    else if(month == 1) printf("February\n");
    else if(month == 2) printf("March\n");
    else if(month == 3) printf("April\n");
    else if(month == 4) printf("May\n");
    else if(month == 5) printf("June\n");
    else if(month == 6) printf("July\n");
    else if(month == 7) printf("August\n");
    else if(month == 8) printf("September\n");
    else if(month == 9) printf("October\n");
    else if(month == 10) printf("November\n");
    else if(month == 11) printf("December\n");
    
    month = (month+1) % 12;

    if(month == 0) printf("January\n");
    else if(month == 1) printf("February\n");
    else if(month == 2) printf("March\n");
    else if(month == 3) printf("April\n");
    else if(month == 4) printf("May\n");
    else if(month == 5) printf("June\n");
    else if(month == 6) printf("July\n");
    else if(month == 7) printf("August\n");
    else if(month == 8) printf("September\n");
    else if(month == 9) printf("October\n");
    else if(month == 10) printf("November\n");
    else if(month == 11) printf("December\n");

    return 0;
}