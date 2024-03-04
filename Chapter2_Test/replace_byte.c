//
//  replace_byte.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/20.
//

#include "Header01.h"
#include <stdio.h>

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    unsigned int *p = &x;
    unsigned char *v = (unsigned char *) p;
    if (is_little_endian())
        v[i] = b;
    else
        v[sizeof(unsigned) - i -1] = b;
    return *p;
}

