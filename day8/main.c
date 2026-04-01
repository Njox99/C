#include <stdio.h>

// struct
struct Body
{
    int age;
    char name[];
};

// union
union Audio
{
    int datePublished;
    int audiolength;
};

enum weekDays
{
    MONDAY = 1,
};

int main()
{
    printf("Unions, enum and struct :)");

    return 0;
}

/*
- common mistakes
1. forgetting to include the semicolon which we use struct, enum and unions.
2. Indescriptive union, enum nd struct names, failing to use naming convention for unions, enums and struct.
*/