//
//  is_little_endian.c
//  Chapter2_Test
//
//  Created by Tobi on 2024/2/20.
//

#include "Header01.h"
// 在小端法机器上运行时返回1
typedef unsigned char* byte_pointer;

int is_little_endian(void) {
  int test_num = 0x3039;
  byte_pointer byte_start = (byte_pointer) &test_num;

  if (byte_start[0] == 0x39) {
    return 1;
  }
  return 0;
}
