#include <stdio.h>

int mynumbers[5] = {10,20,30,40,50};
int *pNumber2 = &mynumbers[1];
int *pLast = &mynumbers[4];

int main() {
 printf("%d", *pNumber2);
 printf("\n%d", *pLast);

 printf("\n%p", &*pNumber2);
 printf("\n%p", &*pLast);
    
 printf("\nDie Differenz: %d", *pLast - *pNumber2);


 return 0;

}