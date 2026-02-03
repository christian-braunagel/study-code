/*
 * File: calculator.c
 * Description: Simple calculator program using functions
 */

#include <stdio.h>

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mult(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int main()
{
    float num1, num2, result = 0;
    char operation;

    printf("Starting Calculator\n");
    printf("This calculator can perform the operations '+', '-', '*', '/' with two digits.\n");

    // get and verify input
    printf("Please enter your first number: ");
    if (scanf("%f", &num1) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // get and verify input
    printf("Please enter your second number: ");
    if (scanf("%f", &num2) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // read operation
    printf("Please enter the operation ('+', '-', '*', '/') you want to perform: ");
    scanf(" %c", &operation); // leading whitespace skips leftover newline characters in the input buffer

    switch (operation)
    {
    case '+':
        result = add(num1, num2);
        break;
    case '-':
        result = sub(num1, num2);
        break;
    case '*':
        result = mult(num1, num2);
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Error: Division by zero.\n");
            return 1;
        }
        result = div(num1, num2);
        break;
    default:
        printf("Unknown operation selected. Program exit.");
        return 1;
    }

    printf("The result of %.2f %c %.2f = %.2f\n", num1, operation, num2, result);

    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    getchar();

    return 0;
}
