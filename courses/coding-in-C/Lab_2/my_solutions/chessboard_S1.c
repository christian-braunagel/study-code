#include <stdio.h>

int main(){

    char array_letters[9] = {'A','B','C','D','E','F','G','H'};
    
    for(int i=8; i>0; i--){
        short number = i;
        for(int f=0; f<8; f++){
            char letter = array_letters[f];
            printf("%c%hd ", letter, number);
            if(f == 7){
                printf("\n\n");
            }
        }
    }

}