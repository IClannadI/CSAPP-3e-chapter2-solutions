//
//  float_f2i.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/28.
//

#include <stdio.h>
#include "Header01.h"

// compute (int)f. if f is NaN, round to zero
// if there is overflow or f is NaN, return 0x80000000

int float_f2i(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    unsigned bias = 0x7f;
    int num;
    unsigned E;
    unsigned M;
    
    if (exp  == 1 && frac !=0){
        return 0x80000000;
    }
    
    if(sign == 1){
/* f is negative */
        if(exp > 31 + bias){
     // less than int_min = -2^31
            return 0x80000000;
        }else if(exp == 31 + bias && frac > 0){
            // frac part makes f less than int_min
            return 0x80000000;
        }else if(exp < 0 + bias){
        // f is between 0~1
            num = 0;
        }else{
            E = exp - bias;
            M = frac | 0x800000;  // turn M into 000000001xxxxxxx....., which is 1-e
            if(E > 23)  // M had already left shifted 23 bits
                num = - M << (E - 23);
            else
                num = - M >> (23 - E);
        }
/* f is positive */
    }else{
        if(exp > 31 - 1 + bias)
            return 0x80000000;
        else if(exp < 0 + bias){
            num = 0;
        }else{
            E = exp - bias;
            M = frac | 0x800000;
            if(E > 23)
                num = M << (E - 23);
            else
                num = M >> (23 - E);
        }
    }
        
    
    return num;
}
