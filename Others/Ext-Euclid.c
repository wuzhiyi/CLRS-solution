/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Extended Euclidean Algorithm
 * 名称:  扩展欧几里得算法
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 辗转相除法求最大公约数，满足贝祖等式：ax+by=gcd(a,b)
 *           若a为负数，则令|a|(-x)+by=gcd(|a|,b), x'=(-x).
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150725       V1.0         wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

int Ext_Euclid_Gcd(int a, int b, int *x, int *y) {
    if (b==0) { //若b=0,则 ax=gcd(a,0)=a
        *x = 1, *y = 0;
        return a;
    }
    else  {
        int r = Ext_Euclid_Gcd(b, a%b, x, y);
        int t = *x;
        *x = *y;
        *y = t - a/b * (*y);
        return r;
    }
}

int main() {
    int x, y;
    int a=400, b=577;
    printf ("贝祖等式 %dx + %dy = gcd(%d, %d)\n", a, b, a, b);
    printf ("gcd(%d,%d)=%d,\tx=%d, y=%d", a, b, Ext_Euclid_Gcd(a, b, &x, &y), x, y);
}
