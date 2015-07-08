/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Problem 2-2
 * 文件名:   BUBBLE-SORT
 * 作者:     baike
 * 语言:     c
 * 内容摘要: 
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150707       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdio.h>

#define SIZE 8

void BUBBLE_SORT(int A[], int n);

void BUBBLE_SORT(int A[], int n)   // n 为数组 A 的元素个数
{
    int i,j,temp;
    for (j=0; j<n-1; j++)
        for (i=0; i<n-1-j; i++) {
            if (A[i]>A[i+1])   // 数组元素大小按升序排列
            {
                temp=A[i];
                A[i]=A[i+1];
                A[i+1]=temp;
            }
        }
}

int main()
{
    int number[SIZE]={95,45,15,78,84,51,24,12};
    int i;
    BUBBLE_SORT(number, SIZE);
    /* 输出已排序数组 number */
    for (i=0; i<SIZE; i++) {
        printf("%d", number[i]);
    }
    printf("\n");
}
