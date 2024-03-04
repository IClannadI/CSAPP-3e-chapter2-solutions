//
//  int_shifts_are_arithmetic.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/20.
//

#include <stdio.h>
#include"Header01.h"

int int_shifts_are_arithmetic(void){
    int flag = -1;
    int shifted_flag = flag >> 2;
    
    return flag == shifted_flag;
}
