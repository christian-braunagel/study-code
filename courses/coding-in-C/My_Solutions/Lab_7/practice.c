#include <stdio.h>
#include <stdlib.h>

int main () {
    int *ptr = malloc(sizeof *ptr);
    if (ptr == NULL) {
        printf ("Memory allocation failed\n");
        return 1;
    }

    printf("Enter an Integer N: ");
    if ( scanf("%d", ptr) !=1 ) {
        printf("Invalid Input");
        free (ptr);
        return 1;
    }

    int *arr = calloc(*ptr, sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        
    }

}