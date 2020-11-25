//SiyuanTang
//z5212799



#include <stdlib.h>
#include<ctype.h>
#include<stdio.h>

int main(int argc , char *argv[]) {
    if (argc != 4) {
        printf("Usage : program name filename int1 int2");
        return 0;
    }
    int first_int = atoi(argv[2]);
    int second_int = atoi(argv[3]);
    FILE *out = fopen(argv[1] , "w+");
    if (out == NULL) {
        printf("invalid file");
    }
    int i = first_int;
    while (i <= second_int) {
        fprintf(out , "%d\n" , i);
        i++;
    }
    fclose(out);
    return 0;
}
