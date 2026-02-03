#include <stdio.h>

char array_letters[9] = {'A','B','C','D','E','F','G','H'};
char array_numbers[9] = {1,2,3,4,5,6,7,8};

int main(){

    int counter_numbers = 0;
    for(int r=0; r<=18; r++){        
        if(r==0 || r==18){
            printf(" ");
            for(int i=0; i<8; i++){
                printf("   %c", array_letters[i]);
            }
        }
        else if(r%2 == 1){
            printf("  +");
            for(int z=0; z<8; z++){
                printf("---+");
            }
        }
        else {
            printf("%d |", array_numbers[7-counter_numbers]);
            
            int colour_code;
            if(counter_numbers%2 == 0){
                colour_code = 0;
            }
            else{
                colour_code = 1;
            }
            
            for(int c=0; c<8; c++){
                if((colour_code+c)%2 == 0){
                    printf("###|");
                }
                else{
                    printf("   |");
                }
            }
            printf(" %d", array_numbers[7-counter_numbers]);
            counter_numbers++; 
        }
    
        printf("\n");
    }

}