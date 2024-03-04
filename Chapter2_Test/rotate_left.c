//
//  rotate_left.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/26.
//

#include <stdio.h>
#include "Header01.h"
unsigned rotate_left(unsigned x, int n){
    int w = sizeof(int) << 3;
    // x左移n位后，与x右移（w-n）取或（保留原有的1）
    return (unsigned) x << n | x >> (w - n - 1) >> 1;  // 考虑到n=0的情况，此时x无法一次性移动32位，因此我们分两次移动。
}
