//
//  unsigned_high_prod.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//

#include <stdio.h>
#include "Header01.h"

int signed_high_prod(int x, int y){
    int64_t mul = (int64_t) x * y;
    return mul >> 31;
}

unsigned unsigned_high_prod(unsigned x, unsigned y){
    int x_high = x >> 31;
    int y_high = y >> 31;
    int signed_prod = signed_high_prod(x, y);
    return signed_prod + x * x_high + y * y_high;
}


