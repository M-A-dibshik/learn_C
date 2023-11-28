#include "main.h"

int open(int age, char *name, char *counter)
{
    printf("Your age: %d\n", age);
    printf("Your name: %s\n", name);
    printf("Your counter: %s\n", counter);
}

int main()
{
    int a;
    int (*p)(int, char *, char *);
    p = open;
    a = p(21, "Mohammed Abdalla", "Sudan");
}