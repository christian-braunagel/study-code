#include <stdio.h>
#include <string.h>


int main(){
 char string[28] = "Curly bird catches the worm";
 char *pString = string;
 int i = 0;
 char *pE = &string[0];

 printf("%s\n", string);
 printf("%s\n",pString);

 *pString = 'E';
 *(pString + 1) = 'a';

 printf("%s\n", pString);


 /*if (string[0] == 'C') {
   string[0] = 'E';
 }

 if (string[1] == 'u') {
   string[1] = 'a';
 }

 while(i<28){ 
   printf("%c",*(pString+i));
   i++;
 }*/
 
 return 0;

} 

/*int main(){
 char word[100];

 printf("welcome to the palindrome determiner!");
 printf("\nChoose your word:");

 scanf("%s", word);

 printf("\n%s", word);

 return 0;
}*/

