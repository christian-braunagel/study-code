#include <stdio.h>

float erste_zahl = 0;
float zweite_zahl = 0;
char operation = '\0';


int main() {
    printf("Willkommen im Taschenrechner! Was kann ich rechnen?\n");
    printf("Eingabe der Ersten Zahl: ");
    scanf("%f", &erste_zahl);

    printf("Eingabe der Zweiten Zahl: ");
    scanf("%f", &zweite_zahl);

    printf("Eingabe des Operators:");
    scanf("%*c%c", &operation);
    
    if(operation=='+'){
        printf("%f %c %f", erste_zahl, operation, zweite_zahl);
        float result = erste_zahl + zweite_zahl;
        printf("\n%c %f", '=', result);
    }
    else if(operation=='-') {
        printf("%f %c %f", erste_zahl, operation, zweite_zahl);
        float result = erste_zahl - zweite_zahl;
        printf("\n%c %f", '=', result);
    }
    else if(operation=='/') {
        printf("%f %c %f", erste_zahl, operation, zweite_zahl);
        float result = erste_zahl / zweite_zahl;
        printf("\n%c %f", '=', result);
    }
    else if(operation=='*') {
        printf("%f %c %f", erste_zahl, operation, zweite_zahl);
        float result = erste_zahl * zweite_zahl;
        printf("\n%c %f", '=', result);
    }
    else {
        printf("Rechnung nicht moeglich. Bitte versuchen Sie es erneut");
    }
    return 0;
}
