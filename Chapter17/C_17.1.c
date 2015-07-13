/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Chapter 17.1
 * 名称:  二进制计数器递增
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 二进制计数器递增16次
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150713      V1.0       wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#define N 8

//递增函数
void INCREMENT(int A[]) {
    int i=0, j;
    while (i<N && A[i]==1) {
        A[i] = 0;
        i = i +1;
    }
    if (i<N) {
        A[i] = 1;
    }
    for (j=N-1; j>-1; j--) {
        printf("%d\t", A[j]);
    }
    printf("\n");
}

//主函数
int main() {
    //初始化
    int A[N-1];
    int x,y;
    
    //调用递增函数
    for (x=0; x<16; x++) {
        printf("x=%d:\t", x);
        INCREMENT(A);
    }
    
    //输出
    printf("Final:\n");
    for (y=N-1; y>-1; y--) {
        printf("%d\t", A[y]);
    }
    return 0;
}
