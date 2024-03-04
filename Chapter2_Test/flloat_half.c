//
//  flloat_half.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/28.
//

#include <stdio.h>
#include "Header01.h"

float_bits float_half(float_bits f){
    unsigned sign = f >> 31;
    unsigned rest = f & 0x7fffffff;  // no sign bit
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    
    /* round to even, we only consider the least 2 significant bits of frac (2 bits lost 1 bit )
     * btw: in binary value, 0 is even and 1 is (least significant bit)odd
     * 00 -> 0 just >> 1
     * 01 -> 0 (round to even)just >> 1
     * 11 -> 1 (round to even) >> 1 then plus 1(turn 1 into 0)
     * 10 -> 1 just >> 1
     */
    
    if(exp == 1 && frac !=0)  // if f is NaN or not
        return f;
    
/* if the last two bits is 11 or not */
    int addition = (frac & 0x3) == 0x3;
    
/* denormalzied*/
    if(exp == 0){
        frac >>= 1;
        frac += addition;
    }else if(exp == 0x1){
        /* normalized turn into denormalized*/
        rest >>= 1;
        rest += addition;
        
/*  not (exp = 0). considering the situation that addition is 1 and after the line 38, the exp part of rest might turn into 00000001 (00000000 + 1) instead of denormalized situation*/
        exp = rest >> 23;
        frac = rest & 0x7fffff;
    }else{
        exp -= 1;
    }
    return sign << 31 | exp << 23 | frac;
}
