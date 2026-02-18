#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //allows for randomization

    int particles[11] = {0,1,0,1,0,1,0,0,0,0};
    int *p_particles = particles;

    int temporary[11] = {0,0,0,0,0,0,0,0,0,0};
    int *p_temporary = temporary;

    int i = 0;
    int turns= 8;

    printf("Welcome to the Particle Simulation");

    while(0<=turns, turns--) {
        printf("\nTurn %d:", 8-turns);
        for(i=0; i<sizeof(temporary)/4; i++) { 
            printf("%d",*(p_particles+i));
        }

        for(i=1;i<sizeof(temporary)/4-1; i++) {
            if (particles[i] == 1) {
                temporary[i] = 0;
                if (rand() % 2 == 0) {
                    temporary[i-1] = temporary[i-1]+1;  // left
                } else {
                    temporary[i+1] = temporary[i+1]+1;   // right
                }
            }
        }

        for(i=0; i<sizeof(temporary)/4; i++){
            if (temporary[i] == 2){
                temporary[i] = 0;
                printf("\nCollision on index %d", i);
            }
        }

        for (int i=0; i<sizeof(temporary)/4-1; i++){
            particles[i] = temporary[i];
        }
    }
    printf("\nEnd of Simulation");
    return 0;
}
