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
 * 20150723       V1.0         wuzhiyi      创建
 * 20150724       V2.0         wuzhiyi      添加快速指数取模函数
 **************************************************************/
#include <stdio.h>

//define A^B mod C
#define A 30
#define B 30
#define C 44
//二分指数取余
int Binary_Remainder(int a) {
    if (a > 1) {
        if (a%2 != 0){
            //printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2+1);
            return (Binary_Remainder(a/2)*Binary_Remainder((a/2)+1))%C;
        }
        else {
            //printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2);
            return (Binary_Remainder(a/2)*Binary_Remainder(a/2))%C;
        }
    }
    return A%C;
}
/* 此处二分幂算法存在优化空间
 * (1)找到指数二分中的临界值，直接计算取余，则不需要继续将指数二分到 1；
 * (2)增加一个备忘数组，每次二分时先搜索备忘数组，如果结果已经存在，则直接调用备忘数组中的结果.
 */

//快速指数取模算法
int Quick_Index_Mod(int a, int b, int c) {
    int I[500], z=-1, y;
    for (; b!=1; b>>=1) {   //b>>=1:先将变量b的各二进制位顺序右移1位，最高位补二进制0，再将结果返回给b
        z++;
        if (b%2==0) I[z]=0;
        else I[z]=1;
    }
    y=(a*a)%c;
    for (; z>0; z--) {
        if (I[z]) y=((y*a%c)*(y*a%c))%c;
        else y=(y*y)%c;
    }
    if (I[0]) y = (y*a%c);
    return y;
}
/* 此处快速指数取模有一个问题：当A=3,B=1,C=5时不成立
 */

int main() {
    printf ("求 A^B mod C\n");
    printf ("A = %d, B = %d, C = %d\n", A, B, C);
    printf ("二分指数取余：%d^%d mod %d = %d\n", A, B, C, Binary_Remainder(B));
    printf ("快速指数取模：%d^%d mod %d = %d\n", A, B, C, Quick_Index_Mod(A, B, C));
}

