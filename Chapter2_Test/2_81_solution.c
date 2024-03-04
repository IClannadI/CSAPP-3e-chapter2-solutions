//
//  2_81_solution.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//
//  A: formule (w-k) 1s and k 0s
//  B: formule (w-k-j) 0s, and k 1s then j 0s
#include <stdio.h>
#include "Header01.h"

int A(int k){
    return -1 << k;
}

int B(int k, int j){
    return ~A(k) << j;
}
