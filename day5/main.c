#include <stdio.h>

int main()
{

    int arr[3] = {10, 20, 30};
    printf("%d\n", arr[0]);
    printf("%d\n", *arr);

    int x = 5;
    int *p = &x;
    int **dd = &p;

    printf("%d\n", x);    // 5
    printf("%d\n", *p);   // 5
    printf("%d\n", **dd); // 5

    return 0;
}

/*
Important note
The array itself is not exactly a normal pointer variable.
But in many expressions, it behaves like a pointer to the first element.

For beginners, it’s fine to think:

array name -> first element’s address
*/