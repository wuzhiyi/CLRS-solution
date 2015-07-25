/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Multiplicative-Inverse
 * 名称:  乘法逆元
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 暴力法，费马小定理，扩展欧几里得算法，（预处理法，神奇推倒公式法）
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150724       V1.0         wuzhiyi      创建
 * 20150725       V2.0         wuzhiyi      添加扩展欧几里得算法
 **************************************************************/
#include <stdio.h>

//初始定义 A*B = 1 mod M
#define A   89
#define M   191

int Divide_Remainder (int, int ,int);
int inv[M]; //Pre_Inv 变量数组声明

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

//扩展欧几里得算法
int Ext_Euclid_Gcd(int a, int b, int *x, int *y) {
    if (b==0) { //若b=0,则 ax=gcd(a,0)=a
        *x = 1, *y = 0;
        return a;
    }
    else  {
        if (Prime(A) && Prime(M)) { //A 与 M 互素, gcd(A,M)=1 时成立
            int r = Ext_Euclid_Gcd(b, a%b, x, y);
            int t = *x;
            *x = *y;
            *y = t - a/b * (*y);
            if (*x < 0) *x = (*x%M + M)%M;  //如果 x 为负数，取模对称的正数
            return r;
        }
        else {
            printf ("A 与 MOD 不互素，不能使用扩展欧几里得定理\n");
            return 0;
        }
    }
}

//预处理法和神奇推倒公式法都还没完善

/* 预处理法
 * 遍历所有 1~i 关于 M 逆元，因为逆元是积性函数，所以只要 M>i 成立即可，不需要 M 必须为素数
 */
void Pre_Inv() {
    inv[0] = inv[1] = 1;
    for (int i=2; i<M; i++) {
        inv[i] = ((M-M/i)*inv[M%i])%M;
    }
}

/* 神奇推倒公式法
 * 以下是我的神奇推倒:
 * 假设 i 的逆元为 Inv(i)
 * 令
 * M = x*i+r (0<i<M)
 * x*i = r (mod M)
 * x*i*Inv(r) = r*Inv(r) = 1 (mod M)
 * 所以
 * i 的逆元 Inv(i) = x*Inv(r)
 */
int Amazing_Inv(int a, int b) {
    return (b-1)/a;
}

int main () {
    int x, y;   //Ext_Euclid_Gcd 的变量初始化
    printf ("求乘法逆元: %d*x = 1 mod %d\n", A, M);
    printf ("暴力求乘法逆元:\tx = %d\n", Brute_Inv(A, M));
    printf ("费马小定理求逆元:\tx = %d\n", Fermat_Inv(A, M));
    if (Ext_Euclid_Gcd(A, M, &x, &y)) {
        printf ("扩展欧几里得求解：\n");
        printf ("扩展欧几里得算法:\tx = %d\n", x);
    }
    printf ("预处理法求解：\n预处理法求逆元:\tx = %d\n", inv[A]);
    printf ("我自己发明的神奇推倒法:\n神器推导法求逆元:\tx = %d", Amazing_Inv(A, M));
}
