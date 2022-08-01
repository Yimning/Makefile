/*
 * @Author: Yimning 1148967988@qq.com
 * @Date: 2022-07-02 10:05:07
*/
#include <stdio.h>
int main(void) {
  printf("this is main function.\r\n---output:Hello,World!\r\n");
  printf("this is bar function.\r\n----output:%d\n", add(44, 44));  // 5
  printf("this is foo function.\r\n----output:%d\n", foo(add(33, 66)));  // 6
  return 0;
  return 0;
}
