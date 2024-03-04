//
//  float_i2f.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/28.
//

#include <stdio.h>
#include "Header01.h"

float_bits float_i2f(int i){
    if(i == 0) 
        return 0;
    int addition = 0;
    unsigned ui = i > 0 ? i : -i;    // avoid arithmetic shifts
    unsigned bias = 127;
    
    /* compute the leftmost one */
    unsigned mark_one = (unsigned) leftmost_one(ui);
    unsigned flag_mark = 0x1;
    /* k means the leftmost one is 2^(k - 1)*/
    int k = 1;
    for(; k < 32 + 1; k++){
        if((mark_one & flag_mark) == mark_one)
            break;
        flag_mark <<= 1;
    }
    
    if(k > 24){
        /* frac part only has 23 bits, int->float would cause overflow, and we should round to even */
        flag_mark >>= 23;
        if((ui & flag_mark) == 0){
            /* the bit to be rounded to is 0 */
            flag_mark >>= 1;
            if((ui & flag_mark) == 0){
                /* the bit behind the bit to be rounded to is 0 */
                ui >>= (k - 24);
            }else{
                /* the bit behind the bit to be rounded to is 1 */
                flag_mark -= 1;
                if((ui & flag_mark) != 0){
                    /* the last (k - 24) bits has one*/
                    ui  = (ui >> (k - 24)) + 1;
                }else{
                    ui >>= (k - 24);
                }
            }
        }else{
            /* the bit to be rounded to is 1*/
            flag_mark >>= 1;
            if((ui & flag_mark) == 0)
                /* the bit behind the bit to be rounded is 0*/
                ui  = (ui >> (k - 24));
            else{
                /*the bit behind the bit to be rounded is 1 */
                flag_mark -= 1;
                if((ui & flag_mark) != 0){
                    /* the last (k - 24 - 1) bits has one*/
                    ui  = (ui >> (k - 24));
                    if(ui == 0xffffff){
                        /* avoid plus one the frac part of ui turn into 25 bits */
                        ui = (ui + 1) >> 1;
                        addition = 1;  // exp part needs to plus 1;
                    }else ui = ui + 1;
                }else{
                    ui >>= (k - 24);
                }
            }
        }
    }else{
        /* no overflow */
        ui <<= (24 - k);
    }
    unsigned exp = k - 1 + bias + addition;;
    unsigned sign = (i > 0) ? 0 : 1;
    unsigned frac = ui & 0x7fffff;
    
    return (sign << 31) | (exp << 23) | frac;
}

//typedef unsigned float_bits;
//
//float_bits float_i2f(int i) {
//    if(i == 0) return 0;
//    unsigned sign = i < 0 ? 1 : 0;
//    unsigned x = i > 0 ? i : -i;//把i转换成无符号数，不然会有算术右移
//    int w = sizeof(int) << 3;
//    int j;
//    for(j = w-1; j >=0; j--) {
//        if ((x >> j) == 1) break; //找到最高位
//    }
//    unsigned exp = 127 + j;
//    unsigned frac;
//    if (j <= 23){
//        frac = (x << (23-j)) ;
//    } else {//x超过2^24就要考虑精度以及舍入
//        frac = (x >> (j-23));
//        unsigned mask = (1<<(j-23)) - 1;
//        //要舍掉的位是形如11、111就进位
//        if( (x&mask) > (1<<(j-24)) ) frac++;
//        //要舍掉的位是形如100，如果尾数最后一位是0，舍入到0（偶数），最后一位是1就进位
//        else if( (x&mask) == 1<<(j-24)  &&  (frac&1)) frac++;
//        if(frac == (1<<24)) exp++; //舍入到偶数超过(1<<24) - 1，指数需要再加1
//    }
//    
//    return sign << 31 | exp << 23 | (frac & 0x7fffff);
//}
