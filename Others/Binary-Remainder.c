//
//  main.c
//  Assignment
//
//  Created by 吴志易 on 15/7/12.
//  Copyright (c) 2015年 吴志易. All rights reserved.
//
/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:
 * 名称:  二分取余
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: (a*b)modc = (amodc)*(bmodc)modc
 *          求9的29次方对264取余
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150723      V1.0       wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <math.h>
#define N 9
int Remainder(long A, long B) {
    return ((A*B)%264);
}

//(9^29)mod 264 = (((9^14)mod 264)*((9^15)mod 264))mod 264
int main() {
    int x = pow(9,7);
    int y = pow(9,8);
    int a,b;
    printf ("9^7 = %d,\t9^8 = %d\n", x, y);
    printf ("9^14 mod 264 =%d\n", a = Remainder(x, x));
    printf ("9^15 mod 264 =%d\n", b = Remainder(x, y));
    printf ("%d\n", Remainder(a, b));
}
