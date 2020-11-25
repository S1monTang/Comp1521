//z5212799
//SiyuanTang

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc , char *argv[]) {
    if (argc <= 1 ) {
        printf("Usage : Program name filename1 filename2 .. filenameN");
        return 1;
    }
    unsigned long int sum = 0;
    int i = 1;
    while (i < argc) {
        struct stat s;
        if (stat(argv[i] , &s) != 0) {
            perror(argv[i]);
            exit(i);
        }
        
        sum += s.st_size;
        printf("%s: %lu bytes\n" , argv[i] , s.st_size);
        i++;
    }
    printf("Total: %lu bytes\n" , sum);
    return 0;
}
