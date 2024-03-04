//
//  mul3div4.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//  multiply 3 then divide 4

#include <stdio.h>
#include "Header01.h"

int mul3div4(int x){
    int x_mul3 = (x << 1) + x;
    return divide_power2(x_mul3, 2);
}
