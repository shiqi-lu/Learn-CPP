// wait3.c - get the statics of child process 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>

int main()
{
    struct rusage rusage;
    pid_t pid = fork();
    if (pid < 0) {
        printf("fail to fork\n");
        exit(0);
    } else if (pid == 0) {
        printf("the child\n");
        exit(0);
    } else {
        printf("the parent\n");
    }

    if (wait3(NULL, 0, &rusage) == -1) {
        perror("fail to wait");
        exit(1);
    }
    printf("utime is %d\n", rusage.ru_utime);
    printf("stime is %d\n", rusage.ru_stime);
    printf("maxrss is %ld\n", rusage.ru_maxrss);
    printf("ixrss is %ld\n", rusage.ru_ixrss);
    printf("idrss is %ld\n", rusage.ru_idrss);
    printf("isrss is %ld\n", rusage.ru_isrss);
    printf("minflt is %ld\n", rusage.ru_minflt);
    printf("majflt is %ld\n", rusage.ru_majflt);
    printf("nswap is %ld\n", rusage.ru_nswap);
    printf("inblock is %ld\n", rusage.ru_inblock);
    printf("oublock is %ld\n", rusage.ru_oublock);
    printf("msgsnd is %ld\n", rusage.ru_msgsnd);
    printf("msgrcv is %ld\n", rusage.ru_msgrcv);
    printf("nsignals is %ld\n" , rusage.ru_nsignals);
    printf("nvcsw is %ld\n", rusage.ru_nvcsw);
    printf("nivcsw is %ld\n", rusage.ru_nivcsw);

    return 0;
}
