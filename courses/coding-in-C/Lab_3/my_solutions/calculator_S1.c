#include <stdio.h>

int main(){

    printf("Type in the two numbers you want to offset:\n");
    float first_number;
    scanf("%f", &first_number);
    float second_number;
    scanf("%f", &second_number);
    printf("Your two numbers: %f, %f\n\n", first_number, second_number);

    printf("Enter the arithmetic operation (+, -, *, /)\n");
    char a_operation;
    scanf(" %c", &a_operation);
    printf("Your arithmetic operation is: %c\n\n", a_operation);

    return 0;
}