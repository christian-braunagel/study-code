#include <stdio.h>

int main() { 
    FILE *fptr = fopen("text.txt", "a");

    fputs("Testing", fptr);

    fclose(fptr);

    FILE *fptr2 = fopen("text.txt", "r");

    char content[100];

    while(fgets(content, 100, fptr2)){
        printf("%s\n", content);
    };

    printf("%s", content);

    fclose(fptr2);

    return 0;
}