#include <stdio.h>

#define NAME "Njox"
#define LOW 90

int main()
{
    printf("Escape sequence \n");

    printf("\tEscape sequence \n");

    printf("\bEscape sequence \" hello \" \n");

    char greeting[] = "Hello";
    putchar(greeting);

    // printf("Chaos \c");

    printf("Chaos \a");

    int count = 12;

    for (int i = 0; i < count; i++)
    {
        printf("%d\n", i);
    }

    return 0;
}

// C = 0.556F - 17.778