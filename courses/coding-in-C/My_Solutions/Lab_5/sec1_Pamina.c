#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp = 42;

    printf("x= %d\n", x);

    printf("x= Value of x\n p= Address of p\n *p= Value of x\n pp= Address of pp\n *pp= Address of p\n **pp= Value of x");
    return 0;
}