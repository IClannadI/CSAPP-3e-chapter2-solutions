//
//  float_twice.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/28.
//

/* float_value = (-1)^s * 2^E * M;
    2.0 * f, the 2 can be multiplied to 2^E or M
*/
#include <stdio.h>
#include "Header01.h"

float_bits float_twice(float_bits f){
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xff;
    unsigned frac = f & 0x7fffff;
    
    if(exp == 1 && frac !=0)  // if f is NaN or not
        return f;
    // we need to consider the denormalized, normalized and overflow
    
    // denormalized, let 2 work on M (we can't change E)
    if(exp == 0){
/* frac part left shift 1 bit, keeping E's bits are all 0(unless the most significant bit of frac is 1)   */
        
        frac <<= 1;
    }else if(exp == 0xff - 1){ 
/* the exp part is 11111110, add 1 we would get inf or NaN, so we just return inf  */
        
        exp = 0xff;
        frac = 0;
    }else{
/* normalized, we make 2 work on 2^E (frac part is unchanged) */
        
        exp += 1;
    }
    return sign << 31 | exp << 23 | frac;
}
