//
//  main.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/17.
//

#include<stdio.h>
#include"Header01.h"
#include <assert.h>
#include <limits.h>
#include <math.h>


int main(int argc, char *argv[]) {
    int a = 2147483647;
    int b = (1 >> 31) - 1;
    printf("%d\n", INT_MAX);
}
/* Decimal to binary model:
 
char *Pbinary = Decimal_To_Bianary(0x3f);
for(int i = 0; i < 32; i++)
    printf("%d", Pbinary[i]);
printf("\n");
 
*/

/*
unsigned a = 0xff;
unsigned b = 0x89abcdef;
unsigned c = 0x12345678;
// b >> ((sizeof(int) -1 ) << 3) ->0x89 最高两位
// b & a = 0xef 最低两位
// c & ~a = 0x123456
// (b & a) | (c & ~a) = 0x123456ef
*/


/*
int uadd_ok(unsigned x, unsigned y){
    return x+y > x;
}
*/

/*
x ^= (x >> 16);
x ^= (x >> 8);
x ^= (x >> 4);
x ^= (x >> 2);
x ^= (x >> 1);
*/


// unsigned 比int更加高级，如果用一个int - unsigned 得到的会是一个unsigned
//而unsgined恒大于0
