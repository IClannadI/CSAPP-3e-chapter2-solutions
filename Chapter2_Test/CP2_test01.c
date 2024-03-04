//
//  main.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/16.
//

#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len){
    size_t i;
    for(i = 0; i < len; i++)
        printf(" %.2x", start[i]);
    printf("\n");
}

void show_int(int x){
    show_bytes((byte_pointer) &x, sizeof(int) );
}

int main(int argc, const char * argv[]) {
    int a = 12345;
    printf("%x\n", a);  //输出0x00003039 参数12345的Hex value
    show_int(a);  //输出 39 30 00 00 小端表示法
    return 0;
}
