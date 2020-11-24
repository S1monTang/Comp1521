//z5212799
//SiyuanTang
//09.28.2020
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#define N_BCD_DIGITS 8

uint32_t packed_bcd(uint32_t packed_bcd);

int main(int argc, char *argv[]) {

    for (int arg = 1; arg < argc; arg++) {
        long l = strtol(argv[arg], NULL, 0);
        assert(l >= 0 && l <= UINT32_MAX);
        uint32_t packed_bcd_value = l;

        printf("%lu\n", (unsigned long)packed_bcd(packed_bcd_value));
    }

    return 0;
}

// given a packed BCD encoded value between 0 .. 99999999
// return the corresponding integer
uint32_t packed_bcd(uint32_t packed_bcd_value) {

    // PUT YOUR CODE HERE
    uint32_t mask = 0x0000000f;
    int result = 0;
    int power = 1;
    int i = 0;
    while (i < N_BCD_DIGITS) {
        result += (packed_bcd_value & mask) * power;
        packed_bcd_value = packed_bcd_value >> 4;
        power *= 10;
        i++;
    }
    return reslut;
}
