/*
 * File: palindrome_caseInsensitive.c
 * Description: Program to identify palindroms but now case-insensitive
 */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char palindrome[100]; // reserve buffer of 100 chars
    const char *p_result_msg = "is a palindrome.";

    printf("Palindrome Detective\n");
    printf("This programs identify if the provided word is a palindrome which can be read from left to right and right to left.\n");

    // get and verify input
    printf("Please enter your word (max. 100 characters): ");

    if (fgets(palindrome, sizeof(palindrome), stdin) == NULL)
    {
        printf("Invalid input.\n");
        return -1;
    }
    palindrome[strcspn(palindrome, "\n")] = '\0';

    // iterate to the half of the string
    // if uneven number of chars in string: ignore last char (in the middle of the string) with floor
    int len_palindrome = strlen(palindrome);
    for (int i = 0; i < floor(len_palindrome / 2); i++)
    {

        // case insensitive comparision
        if (tolower(palindrome[i]) != tolower(palindrome[len_palindrome - i - 1]))
        {
            p_result_msg = "is not a palindrome.";
            break;
        }
    }

    printf("Your provided word \"%s\" %s\n", palindrome, p_result_msg);
    return 0;
}
