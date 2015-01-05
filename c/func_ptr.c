#include <stdio.h>
int (*p1)(int, int) = NULL;
int (*p2)(int, int) = NULL;
int (*p3)(int, int) = NULL;
int (*p4)(int, int) = NULL;

int add(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}

int mul(int a, int b)
{
    return a * b;
}

int div(int a, int b)
{
    return a / b;
}

int main()
{
    int a, b;
    p1 = add;
    p2 = sub;
    p3 = mul;
    p4 = div;
    a = 2;
    b = 1;

    printf("add : %d\n", (*p1)(a, b));
    printf("sub : %d\n", (*p2)(a, b));
    printf("mul : %d\n", (*p3)(a, b));
    printf("div : %d\n", (*p4)(a, b));

    return 0;
}
