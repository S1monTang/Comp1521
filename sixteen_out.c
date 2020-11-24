//z5212799
//SiyuanTang
//09/28/2020
// Sample solution for COMP1521  exercises
//
// Convert a 16-bit signed integer to a string of binary digits

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BITS 16

char *sixteen_out(int16_t value);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= INT16_MIN && l <= INT16_MAX);
        int16_t value = l;

        char *bits = sixteen_out(value);
        printf("%s\n", bits);

        free(bits);
    }

    return 0;
}

// given a signed 16 bit integer
// return a null-terminated string of 16 binary digits ('1' and '0')
// storage for string is allocated using malloc
char *sixteen_out(int16_t value) {

    // PUT YOUR CODE HERE
    char *result = malloc(17 * sizeof(char));
    result[16] = '\0';
    int16_t mask = 0x0001;
    int i = value;
    int counter = 15;
    while (counter >= 0) {
        if ((i & mask) == 1) {
            result[counter] = '1';
        } else {
            result[counter] = '0';
        }
        i = i >> 1;
        counter--;
    }
    return result;

}
