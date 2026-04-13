#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 1. Allocate memory for a single integer using malloc
    int *ptr = malloc(sizeof *ptr);
    if (ptr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Ask user for integer N
    printf("Enter an integer N: ");
    if (scanf("%d", ptr) != 1)
    {
        printf("Error when reading input value");
        free(ptr);
        return 1;
    }

    // 2. Allocate memory for N integers using calloc
    int *arr = calloc(*ptr, sizeof(int));

    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        free(ptr);
        return 1;
    }

    /*
    Differences between malloc and calloc:

    1. Initialization:
       - malloc(): does NOT initialize memory (contains garbage values)
       - calloc(): initializes all allocated memory to 0

    2. Parameters:
       - malloc(): takes 1 argument → total size in bytes
       - calloc(): takes 2 arguments → number of elements and size of each element; used for arrays
    */

    // 3. Fill array with squares: arr[i] = i * i
    for (int i = 0; i < *ptr; i++)
    {
        arr[i] = i * i;
    }

    // 4. Resize array to 2*N using realloc
    int *p_temp = realloc(arr, 2 * (*ptr) * sizeof(int));

    if (p_temp == NULL)
    {
        printf("Reallocation failed.\n");
        free(arr);
        free(ptr);
        return 1;
    }

    arr = p_temp;

    // Fill new part of the array
    for (int i = *ptr; i < 2 * *ptr; i++)
    {
        arr[i] = i * i;
    }

    // 5. Print the array
    printf("Array contents:\n");
    for (int i = 0; i < 2 * *ptr; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 6. Free all allocated memory
    free(ptr);
    free(arr);

    return 0;
}
