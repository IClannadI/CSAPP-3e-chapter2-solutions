//
//  my_calloc.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "Header01.h"

void *my_calloc(size_t nmemb, size_t size){
   if(nmemb == 0 || size == 0)
       return NULL;
    size_t buf_size = nmemb * size;
    
    // judge whether overflow or not
    if(nmemb == buf_size / size){
        void *Pointer = malloc(buf_size);
        memset(Pointer, 0, buf_size);
        return Pointer;
    }
    
    return NULL;
}
