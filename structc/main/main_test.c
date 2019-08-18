﻿#include "head.h"

//
// EXTERN_TEST  - 单元测试宏, 并打印执行时间
// ftest        : 测试函数
// ...          : 可变参数
//
#define EXTERN_TEST(ftest, ...)                              \
do {                                                         \
    extern void ftest();                                     \
    clock_t $s = clock();                                    \
    ftest (__VA_ARGS__);                                     \
    double $e = (double)clock();                             \
    printf(STR(ftest)" run %lfs\n", ($e-$s)/CLOCKS_PER_SEC); \
} while(0)


//
// main_test - main run test
// return    : void
//
void main_test(void) {
    puts("*--------------------------------** main test *--------------------------------*");

    //
    // 开始你的表演, 单元测试
    //

    EXTERN_RUN(md5_test);
    EXTERN_RUN(utf8_test);
    EXTERN_RUN(dict_test);
    EXTERN_RUN(strext_test);

    puts("*--------------------------------** main test *--------------------------------*");
}
