/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Modular_Exponentiation
 * 名称:  指数取模算法
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 不同方法对指数取模
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150723       V1.0         wuzhiyi      创建
 * 20150724       V2.0         wuzhiyi      添加快速指数取模函数
 * 20150724       V2.1         wuzhiyi      添加同余公式和反复平法
 **************************************************************/
#include <stdio.h>

//define A^B mod M
#define A 9
#define B 29
#define M 264

//二分指数取余
int Divide_Remainder(int a) {
    if (a > 1) {
        if (a%2 != 0){
            //printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2+1);
            return (Divide_Remainder(a/2)*Divide_Remainder((a/2)+1))%M;
        }
        else {
            //printf ("Remainder(%d) & Remainder(%d)\n", a/2, a/2);
            return (Divide_Remainder(a/2)*Divide_Remainder(a/2))%M;
        }
    }
    return A%M;
}
/* 此处二分幂算法存在优化空间
 * (1)找到指数二分中的临界值，直接计算取余，则不需要继续将指数二分到 1；
 * (2)增加一个备忘数组，每次二分时先搜索备忘数组，如果结果已经存在，则直接调用备忘数组中的结果.
 */

//利用同余公式(Congruence Formula)对幂取模
int Congru_Mod (int a, int b, int m) {
    int result = 1;
    for (int i=0; i<b; i++) {
        result = (result*a)%m;
    }
    return result;
}

//快速指数取模算法
//使用栈记录二进制幂
int Quick_Index_Mod(int a, int b, int m) {
    int I[500], z=-1, y;
    for (; b!=1; b>>=1) {   //b>>=1:先将变量b的各二进制位顺序右移1位，最高位补二进制0，再将结果返回给b
        z++;
        if (b%2==0) I[z]=0;
        else I[z]=1;
    }
    y=(a*a)%m;
    for (; z>0; z--) {
        if (I[z]) y=((y*a%m)*(y*a%m))%m;
        else y=(y*y)%m;
    }
    if (I[0]) y = (y*a%m);
    return y;
}
/* 此处快速指数取模有一个问题：当A=3,B=1,C=5时不成立
 */

//反复平方法(Right-to-Left Bianry Method)
//也叫 Montgomery 算法
//将幂B转换为二进制表示，并从右至左扫描其每一位(从低到高)
int Montgomery(int a, int b, int m) {
    int result = 1;
    int base = a;
    while (b>0) {
        if ((b & 1)==1) {   //如果第i位为1，则表示该位需要参与模运算
            result = (result*base)%m;
        }
        base = (base*base)%m;   //第i位位0，不需要参与模运算
        b>>=1;  //b右移一位
    }
    return result;
}

int main() {
    printf ("求 A^B mod M\n");
    printf ("A = %d, B = %d, M = %d\n", A, B, M);
    printf ("二分指数取余：%d^%d mod %d = %d\n", A, B, M, Divide_Remainder(B));
    printf ("同余公式取模：%d^%d mod %d = %d\n", A, B, M, Congru_Mod(A, B, M));
    printf ("快速指数取模：%d^%d mod %d = %d\n", A, B, M, Quick_Index_Mod(A, B, M));
    printf ("反复平方法：  %d^%d mod %d = %d\n", A, B, M, Montgomery(A, B, M));
}
