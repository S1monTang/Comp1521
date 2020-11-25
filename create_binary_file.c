//z5212799
//SiyuanTang

#include<stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc , char *argv[]) {
    if (argc < 3) {
        printf("Usage : programname filename interge1 - n\n");
        return 0;
    }
    FILE *out = fopen(argv[1] , "w+");
    if (out == NULL) {
        printf("invalid input");
        return 0;
    }
    long int i = 2;
    while (i < argc) {
        int c = atoi(argv[i]);
        fputc(c , out);
        i++;
    }
    fclose(out);
    return 0;
}
