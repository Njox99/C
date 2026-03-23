#include <stdio.h>

int main()
{
    // int
    printf("Size of int is: %zu \n", sizeof(int));       // whole number positive or negative %d
    printf("Size of double is: %zu \n", sizeof(double)); //
    printf("Size of char is: %zu \n", sizeof(char));
    printf("Size of short is: %zu \n", sizeof(short));
    printf("Size of long is: %zu \n", sizeof(long));
    printf("Size of float is: %zu \n", sizeof(float));
    printf("Size of long long is: %zu \n", sizeof(long long));

    return 0;
}

// int, double, char, short, long, long long.

// remember it prints in term of bytes and not bits.
// 1 byte = 8 bits