//z5212799
//SiyuanTang
//05/10/2020
// Extract the 3 parts of a float using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"

// separate out the 3 components of a float
float_components_t float_bits(uint32_t f) {
    // PUT YOUR CODE HERE
    float_components_t *new = malloc(sizeof(float_components_t));
    uint32_t mask_exp = 0x000000ff;
    // 0 0000 0000 00000000000000011111111
    uint32_t mask_frac = 0x007fffff;
    // 0 0000 0000 11111111111111111111111
    new->sign = f >> 31;
    new->exponent = (f >> 23) & mask_exp;
    new->fraction = f & mask_frac;
    return *new;
}

// given the 3 components of a float
// return 1 if it is NaN, 0 otherwise
int is_nan(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 255) && (f.fraction > 0 )) {
        return 1;
    }
    return 0;
}

// given the 3 components of a float
// return 1 if it is inf, 0 otherwise
int is_positive_infinity(float_components_t f) {
    // PUT YOUR CODE HERE
    if ((f.exponent == 255) && (f.fraction == 0) && (f.sign == 0)) {
        return 1;
    }
    return 0;
}

// given the 3 components of a float
// return 1 if it is -inf, 0 otherwise
int is_negative_infinity(float_components_t f) {
    // PUT YOUR CODE HERE
    if (f.sign == 1 && f.exponent == 0x000000ff) {
        return 1;
    }

    return 0;
}

// given the 3 components of a float
// return 1 if it is 0 or -0, 0 otherwise
int is_zero(float_components_t f) {
    // PUT YOUR CODE HERE
    if (f.exponent == 0 && f.fraction == 0) {
        return 1;
    }

    return 0;
}
