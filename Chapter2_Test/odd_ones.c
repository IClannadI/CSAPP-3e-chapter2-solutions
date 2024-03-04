//
//  odd_ones.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/20.
//

//当x(二进制表示)中有奇数个1时，输出1；否则输出0。 假设int是32位。
#include <stdio.h>
#include "Header01.h"
int odd_ones(unsigned x){
    
    x ^= x>>1;
    x ^= x>>2;
    x ^= x>>4;
    x ^= x>>8;
    x ^= x>>16;
    // 上述代码将0～31位同时做xor运算，并将结果放在第0位
    return x & 1;
    // 与1（第0位为1）做and运算，结果为1意味着上述32次异或结果为1，即有奇数个1。
}
