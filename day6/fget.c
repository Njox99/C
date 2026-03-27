#include <stdio.h>

int main()
{
    printf("fgets bro!");

    char jina[10];
    printf("Enter your name: ");

    fgets(jina, sizeof(jina), stdin);

    printf("Jambo: %s", jina);

    return 0;
}

// od, xxd, hd