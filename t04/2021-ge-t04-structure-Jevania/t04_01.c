// 12S20048 - Jevania

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct kamus{
	char kata[20];
	char arti[80];
};

int main() {
    char perintah[50];
	char toFind[50];
	int i=0;
	int a, num = 0;
	struct kamus myKamus[100];
	bool end=false;
	
	while(!end){
        scanf("%s", perintah);

        if(strcmp(perintah, "register") == 0){
            if(num < 5){
    		    scanf("%s", myKamus[i].kata);
    		    scanf("%s", myKamus[i].arti);
    		    num++;
            }

        }else if(strcmp(perintah, "find")== 0){
    		scanf("%s", toFind);
    		for(a=0;a<num;a++){
    			if(strcmp(toFind, myKamus[a].kata) == 0){
    			}
    		}
        }else if(strcmp(perintah, "---") == 0){
			for(a=0;a<num;a++){
			printf("%s#%s\n", myKamus[a].kata, myKamus[a].arti);
			}
            end=true;
        }
	}
    if(num == 0){
        printf("\n");
    }
    
    return 0;
}