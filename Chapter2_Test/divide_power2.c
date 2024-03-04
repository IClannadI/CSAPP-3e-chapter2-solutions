//
//  divide_power2.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//  Divide by power of 2. Assume 0 <= K < w-1
//  use correct type of rounding


// when x is positive we can simply do right shift
// But when x is negetive, when we simply do right shift, the result would do lower rounding, for example: -12340/2^4 the real value should be -771.25, we hope get -771; whereas the result is you get is -772
// to solve the problem above, we need to set a offset, if the divisor is 2^k, we set x to x + 2^k -1 then we do right shift, and the result is -771 (only when x is negetive and divide power of 2 can we use the offset above)


#include <stdio.h>
#include "Header01.h"
#include <limits.h>

// calculate x/2^k and rounding it
int divide_power2(int x, int k){
    int flag_int = INT_MIN;
    // judge the symbol
    int is_neg = x & flag_int;
    // add the offset when x is negetive
    is_neg && (x = x + (1 << k) - 1) ;
    return x >> k;
}
