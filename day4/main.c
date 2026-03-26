#include <stdio.h>

int main()
{
    // printf("Pointers \n");

    int x = 42;
    int *p = &x;

    printf("Before: %d\n", *p);

    // change value of pointer p
    *p = 32;
    printf("After: %d\n", *p);

    *p = NULL;
    printf("After Setting to NULL: %d\n", *p);

    int arr[] = {10, 20, 30};
    int *p = arr;

    return 0;
}