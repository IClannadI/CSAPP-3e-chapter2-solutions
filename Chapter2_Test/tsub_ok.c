//
//  tsub_ok.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//  if x-y doesn't overflow, return 1; 0 otherwise

#include <stdio.h>
#include <limits.h>
#include "Header01.h"

int tsub_ok(int x, int y){
    int flag_int = INT_MIN;  // used to judge the symbol
    int ret = 1;
    int sub = x-y;

    // if y == INT_MIN return 0
    (y == INT_MIN) && (ret = 0);
    // if x>0,y<0 and sub < 0 ->positive overflow
    int pos_over = !(x & flag_int) && (y & flag_int) && (sub & flag_int);
    // if x<0,y>0 and sub >0 ->negetive overflow
    int neg_over = (x & flag_int) && !(y & flag_int) && !(sub & flag_int);
    // if there is any pos or neg overflow, return 0;
    (pos_over || neg_over) && (ret = 0);
    
    return ret;
}
