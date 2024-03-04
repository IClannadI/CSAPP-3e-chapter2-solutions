//
//  Header01.h
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/20.
//

#ifndef Header01_h
#define Header01_h
#include <stddef.h>  // avoid "unknow type name 'size_t'" error

// 位级浮点编码规则
typedef unsigned float_bits;


int is_little_endian(void);
unsigned replace_byte(unsigned x, int i, unsigned char b);
int int_shifts_are_arithmetic(void);
int odd_ones(unsigned x);
char * Decimal_To_Bianary(int x);
int leftmost_one(unsigned x);
int lower_one_mask(int n);
unsigned rotate_left(unsigned x, int n);
int saturating_add(int x, int y);
int tsub_ok(int x, int y);
unsigned unsigned_high_prod(unsigned x, unsigned y);
void *my_calloc(size_t nmemb, size_t size);
int divide_power2(int x, int k);
int mul3div4(int x);
int threefourths(int x);
int A(int k);
int B(int k, int j);
float_bits float_negate(float_bits f);
float_bits float_twice(float_bits f);
float_bits float_half(float_bits f);
float_bits float_i2f(int i);

#endif /* Header01_h */
