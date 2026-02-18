#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{

    // using indexing
    for (int i = 0; i < argc; i++)
    {
        // using indexing
        printf("Argument %d at address \"%p\" has content: %s (length: %d)\n", i, argv[i], argv[i], strlen(argv[i]));

        // using pointer dereferencing
        printf("Argument %d at address \"%p\" has content: %s (length: %d)\n", i, *(argv + i), *(argv + i), strlen(*(argv + i)));
    }

    return 0;
}

/* ******* Relation: indexing vs dereferencing **********
argv[i]:
    Typ: char *
    Wert: Address of the first character of the i-th string

argv + i:
    Typ: char **
    Wert: Address of the i-th pointer in argv-Array
*(argv + i):
    Typ: char *
    Wert: Address of the first character of the i-th string
*/

/* ******* arrays vs. pointers *********
   - Given an array: int arr[3] = {1,2,3};
   - The array name points to the corresponding memory block {1,2,3}
   - Whenever the array name is used in a statement, it decays to a pointer
   - e.g. arr + 2 handles arr as if it would be a pointer
   - or e.g. someFunction(arr) -> a pointer to the arr is handed over
   - Exceptions: sizeof(arr) and &arr do not let arr decay to a pointer
   - However, arr cannot be reassigned e.g. arr = ...
*/