#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "Njox";
    char destinaton[2];

    strcpy(destinaton, source);

    // print source string
    printf("Source string: %s\n", source);

    // print destination string
    printf("Destination string: %s\n", destinaton);

    printf("Size of destination: %zu\n", sizeof(destinaton));
    // \0

    return 0;
}

// use strncpy carefully, or better, snprintf/fgets depending on the case