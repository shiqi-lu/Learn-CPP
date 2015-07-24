// copy1.c - use fwrite and fread to copy
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    FILE * fp1, * fp2;
    char buf[1024];
    int nbytes;
    if (argc != 3) {
        printf("wrong command\n");
        exit(1);
    }

    if ((fp1 = fopen(argv[1], "rb")) == NULL) {
        perror("fail to open");
        exit(1);
    }

    if ((fp2 = fopen(argv[2], "wb")) == NULL) {
        perror("fail to open");
        exit(1);
    }

    while ((nbytes = fread(buf, sizeof(char), 1024, fp1)) > 0) {
        if (fwrite(buf, sizeof(char), nbytes, fp2) == -1) {
            perror("fail to write");
            exit(1);
        }
    }

    if (nbytes == -1) {
        perror("fail to read");
        exit(1);
    }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
