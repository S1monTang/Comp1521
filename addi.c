// Sample solution for COMP1521 lab exercises
//
// generate the opcode for an addi instruction
//SIyuanTang
//z5212799

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

#include "addi.h"

// return the MIPS opcode for addi $t,$s, i
uint32_t addi(int t, int s, int i) {

    uint32_t code = 0x8;      //00000000000000000000000000001000
    code = code << 5;           //00000000000000000000000100000000
    code = code | s;            //000000000000000000000001000sssss
    code = code << 5;           //0000000000000000001000sssss00000
    code = code | t;            //0000000000000000001000sssssttttt
    code = code << 16;          //001000sssssttttt0000000000000000
    i = i & 0xffff;
    code = code | i;            //001000ssssstttttIIIIIIIIIIIIIIII
    return code;
}
