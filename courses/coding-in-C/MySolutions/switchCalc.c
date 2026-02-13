#include <stdio.h>

int main(){
    float num1, num2, result;
    char operation;

    printf("Gib die erste Nummer ein: ");
    scanf("%f", &num1);

    printf("Gib die zweite Nummer ein: ");
    scanf("%f", &num2);

    printf("Such dir eine Rechenoperarion aus (+, -, *, /): ");
    scanf(" %c", &operation);

    switch (operation) {
        case '+':
        result = num1 + num2;
        printf("Das Ergebnis aus %.2f + %.2f = %.2f\n", num1, num2, result);
        break;
    
        case '-':
        result = num1 - num2;
        printf("Das Ergebnis aus %.2f - %.2f = %.2f\n", num1, num2, result);
        break;
    
        case '*':
        result = num1 * num2;
        printf("Das Ergebnis aus %.2f * %.2f = %.2f\n", num1, num2, result);
        break;
    
        case '/':
         if (num2 == 0) {
            printf("Error: Division durch Null ist nicht erlaubt\n");
        } else {
            result = num1 / num2;
            printf("Das Ergebnis aus %.2f / %.2f = %.2f\n", num1, num2, result);
        }
        break;

        default:
        printf("Error: Unzulaessige Operation.\n");
    }

    return 0;
}