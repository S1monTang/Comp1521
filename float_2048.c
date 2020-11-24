// Multiply a float by 2048 using bit operations only

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "floats.h"
float_components_t float_bits(uint32_t f);
// float_2048 is given the bits of a float f as a uint32_t
// it uses bit operations and + to calculate f * 2048
// and returns the bits of this value as a uint32_t
//
// if the result is too large to be represented as a float +inf or -inf is returned
//
// if f is +0, -0, +inf or -inf, or Nan it is returned unchanged
//
// float_2048 assumes f is not a denormal number
//
uint32_t float_2048(uint32_t f) {
    // PUT YOUR CODE HERE
    float_components_t new = float_bits(f);
    if ((new.exponent == 255) && (new.fraction > 0 )) {
        return f;
    } else if (new.exponent > 243) {
        if (new.sign == 0) {
            return ((u_int32_t)0 | (0x000000ff << 23));
        } else {
            return (((u_int32_t)0 | (0x000000ff << 23))|(u_int32_t)1 << 31);
        }
    } else if (new.exponent == 0x000000ff||
    (new.exponent == 0 && new.fraction == 0)) {
        return f;
    } 
    new.exponent += 11;
    return (new.sign << 31 )| (new.exponent << 23) | (new.fraction);
}



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
