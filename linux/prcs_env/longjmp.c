// longjmp.c - setjmp judge longjfmp
#include <stdio.h>
#include <setjmp.h>

jmp_buf env;
void f()
{
    longjmp(env, 10);
}

int main()
{
    int val = setjmp(env);
    if (val != 0) {
        printf("after long jump, the value is %d\n", val);
    } else {
        printf("ready to jump\n");
        f();
    }

    return 0;
}
