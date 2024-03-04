//
//  float_negate.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/28.
//

#include <stdio.h>
#include "Header01.h"

float_bits float_negate(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;  // get exp part, the rest bits of f are 0s
    unsigned frac = f & 0x7fffff;  // get frac part
    
    // is NaN or not?
    if((exp == 1) && (frac != 0))
        return f;
    
    // compute -f
    sign = sign ^ 1;  // or : sign = ~sign;
    return (sign << 31) | (exp << 23) | frac;
}
