//
//  saturateing_add.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/26.
//  used when there is saturations in addition between two integers

#include <stdio.h>
#include <limits.h>
#include "Header01.h"
int saturating_add(int x, int y){
    // 判断是否溢出：1.x<0,y<0 ;sum>0 ->负溢出 2. x>0,y>0;sum<0 ->正溢出
    int sum = x + y;
    int flagInt = INT_MIN;  //用于判断符号位
    int pos_over = !(x & flagInt) && !(y & flagInt) && (sum & flagInt);
    int neg_over = (x & flagInt) && (y & flagInt) && !(sum & flagInt);
    
    ((pos_over && (sum = INT_MAX))||(neg_over && (sum = INT_MIN)));
    
    return sum;
}
