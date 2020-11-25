//SiyuanTang
//z5212799

#include<stdio.h>
#include <ctype.h>

int main(int argc , char *argv[]) {
    if (argc != 2) {
        printf("Usage : programname filename\n");
        return 0;
    }
    FILE *out = fopen(argv[1] , "r");
    if (out == NULL) {
        printf("invalid input");
        return 0;
    }
    int c = fgetc(out);
    long int i = 0;
    while (c != EOF) {
        printf("byte %4ld: %3d 0x%02x" , i , c , c);
        if (isprint(c) != 0) {
            printf(" '%c'" , c);
        }
        printf("\n");
        i++;
        c = fgetc(out);
    }
    fclose(out);
    return 0;
}


