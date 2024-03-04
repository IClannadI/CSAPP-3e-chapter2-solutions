//
//  lower_one_mask.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/26.
//  Mark with least signicant n bits set to 1
//  for example: n=6 -> 00000000000000000000000000111111


#include <stdio.h>
#include"Header01.h"
int lower_one_mask(int n){
    int w = sizeof(int) << 3;  // 假设不知道int占多少位
    return (unsigned) -1 >> (w - n);
}
