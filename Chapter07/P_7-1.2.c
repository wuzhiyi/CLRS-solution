/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 7-1
 * 名称:  HOARE-PARTITION
 * 作者:  windmissing
 * 语言:  c
 * 内容摘要: Hoare划分
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdbool.h>

int Hoare_Partition(int *A, int p, int r) {
    int x=A[p],
        i=p-1,
        j=r+1;
    
    while(true)
    {
        do { j--; } while (A[j]>x);
        do { i++; } while (A[i]<x);
        
        if (i<j)
            swap(A[i],A[j]);
        else
            return j;
        print(A,12);
    }
}

void Hoare_QuickSort(int *A, int p, int r) {
    if (p<r)
    {
        int q=Hoare_Partition(A,p,r);
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}
