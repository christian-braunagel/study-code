/*
 * File: palindrome.c
 * Description: Program to identify palindroms
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char palindrome[100]; // reserve buffer of 100 chars
    const char *p_result_msg = "is a palindrome.";

    printf("Palindrome Detective\n");
    printf("This programs identify if the provided word is a palindrome which can be read from left to right and right to left.\n");

    // get and verify input
    printf("Please enter your word (max. 99 characters): ");
    if (scanf("%99s", palindrome) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // iterate to the half of the string
    // if uneven number of chars in string: ignore last char (in the middle of the string) with floor
    int len_palindrome = strlen(palindrome);
    for (int i = 0; i < floor(len_palindrome / 2); i++)
    {

        // case sensitive comparision
        if (palindrome[i] != palindrome[len_palindrome - i - 1])
        {
            p_result_msg = "is not a palindrome.";
            break;
        }
    }

    printf("Your provided word \"%s\" %s\n", palindrome, p_result_msg);
    return 0;
}
