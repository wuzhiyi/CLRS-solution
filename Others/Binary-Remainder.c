/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:
 * 名称:  任意指数的二分取余
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 任意数的N次方取余
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150723      V1.0       wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

//define A^B mod C
#define A 9
#define B 29
#define C 264

//二分递归指数直到为 1，返回
int Remainder(int a) {
    if (a > 1) {
        //判断指数奇偶
        if (a%2 != 0){
            printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2+1);
            return (Remainder(a/2)*Remainder((a/2)+1))%C;
        }
        else {
            printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2);
            return (Remainder(a/2)*Remainder(a/2))%C;
        }
    }
    return A%C;
}

int main() {
    printf ("求 A^B mod C\n");
    printf ("A = %d, B = %d, C = %d\n", A, B, C);
    printf ("%d^%d mod %d = %d\n", A, B, C, Remainder(B));
}
/* 存在优化空间
 * 即找到指数二分中的临界值，直接计算取余
 * 则不需要继续将指数二分到 1。
 */
