#include <stdio.h>

int main() {
 float erste_zahl = 0;
 float zweite_zahl = 0;
 char operator ='\0';

 printf("Willkommen im Taschenrechner! Was kann ich rechnen?\n");
 printf("Eingabe der Ersten Zahl:");
 scanf("%f", &erste_zahl);
 printf("Eingabe Zweite Zahl:");
 scanf("%f", &zweite_zahl);
 printf("Eingabe des Operators:");
 scanf("%*c%c", &operator);

    switch(operator) {
     case '*':
         printf("%f %c %f", erste_zahl*zweite_zahl);
            break;
     case '+':
         printf("%f %c %f", erste_zahl+zweite_zahl);
            break;
     case '-':
         printf("%f %c %f", erste_zahl-zweite_zahl);
            break;
     case '/':
         printf("%f %c %f", erste_zahl/zweite_zahl);
            break;
     default:
         printf("Rechnung konnte nicht durchgefuehrt werden. Bitte versuchen Sie es nochmal");
    }
 return 0;
}