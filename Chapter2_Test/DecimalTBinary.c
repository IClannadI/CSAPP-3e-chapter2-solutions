//
//  DecimalTBinary.c
//  Chapter2_Test
//  used to translate decimal value to binary value
//  Created by Tobi on 2024/2/26.
//

#include <stdio.h>
#include <stdlib.h>
#include "Header01.h"
char * Decimal_To_Bianary(int x){
    int w = sizeof(int) << 3;  // 假设int占32位
    char *Pbinary = (char *)malloc(w);
    
    int i = w-1;
    do{
        Pbinary[i] = x % 2;
        x = x / 2;
        i--;
    }while(x != 0);
    
    return Pbinary;
}
