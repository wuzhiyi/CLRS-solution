/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Multiplicative-Inverse
 * 名称:  乘法逆元
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 暴力法，费马小定理，（欧几里得扩展，神奇推倒）
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150724      V1.0        wuzhiyi     创建
 **************************************************************/
#include <stdio.h>

//初始定义 A*B = 1 mod M
#define A   13
#define M   23

int Divide_Remainder (int, int ,int);

//暴力求解逆元
int Brute_Inv(int a, int m) {
    int i=0;
    //判断 a 与 m 是否互素
    if (a%m!=0 && m%a!=0) {
        //循环求解
        for (; i<m; i++) {
            if (i*a%m == 1) {
                return i;
                break;
            }
        }
    }
    else {
        printf ("a 与 m 不互素，无解\t");
    }
    return i;
}

//判断是否为质数
int Prime(int a) {
    int result = 1;
    
    //循环递增判断是否存在因子
    for (int i=2; i<=a/2; i++) {
        if (a%i == 0) {
            printf ("%d is not prime,\tbecause %d = %d*%d\n", a, a, i, a/i);
            result = 0;
            break;
        }
    }
    if (result != 0) {
        printf ("%d is prime\n", a);
    }
    return result;
}

/* 费马小定理 Fermat's Little Theorem
 * MOD 必须为质数才成立
 * 利用公式: a^(p-1)%MOD = 1, 则其逆元为 a^(p-2)
 */
int Fermat_Inv(int a, int m) {
    printf ("费马小定理求解：\n");
    //判断MOD是否为质数
    if (Prime(A) && Prime(M)) {
        return Divide_Remainder(A, M-2, M);
    }
    else printf ("A 与 MOD 不全为质数，不能使用费马小定理\n");
    return 0;
}

//二分指数取余
int Divide_Remainder(int a, int b, int m) {
    if (b > 1) {
        if (b%2 != 0){
            return (Divide_Remainder(a, b/2, m)*Divide_Remainder(a, b/2+1, m)%m);
        }
        else {
            return (Divide_Remainder(a, b/2, m)*Divide_Remainder(a, b/2, m))%m;
        }
    }
    return a%m;
}

int main () {
    printf ("求乘法逆元: %d*x = 1 mod %d\n", A, M);
    printf ("暴力求乘法逆元:\tx = %d\n", Brute_Inv(A, M));
    printf ("费马小定理求逆元:\tx = %d\n", Fermat_Inv(A, M));
}
