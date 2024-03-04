//
//  leftmost_one.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/26.
//  Keep the leftmost 1 (Binary value)
//  such as: 0xff00->0x8000
//  equals: 00000000000000001111111100000000
//      ->  00000000000000001000000000000000
#include "Header01.h"
#include <stdio.h>
int leftmost_one(unsigned x){
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
// 让x最左边的1保留，使其右侧所有位全部为0；
    return x ^ (x >> 1);  // 让x右移一位，异或，保留最左侧一；
}
