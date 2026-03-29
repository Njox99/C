#include <stdio.h>

void greetUser()
{
    printf("Hello Njox \n");
}

void printUser(char name[])
{
    printf("Hello %s", name);
}

int calculateAge(int yearOfBirth)
{
    int thisYear = 2025;
    return thisYear - yearOfBirth;
}

int main()
{

    printf("Day 7 bro! \n");

    greetUser();

    printUser("Njox");

    printf("Your age is: %d\n", calculateAge(2001));

    return 0;
}