/*
 * @Author: Yimning 1148967988@qq.com
 * @Date: 2022-07-02 10:05:07
*/
#include <stdio.h>
#include "bar/bar.h"
#include "foo/foo.h"
int main(void) {
  printf("this is bar function---output:%d\n", add(44, 44));  // 5
  printf("this is foo function---output:%d\n", foo(add(33, 66)));  // 6
  return 0;
}
