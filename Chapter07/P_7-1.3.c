/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 7-1
 * 名称:  HOARE-PARTITION
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: Hoare划分
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdbool.h>

int hoare_partition(int A[], int p, int r) {
    int x=A[p],
        i=p-1,
        j=r,
        tmp;
    
    while(true) {
        do { j--; } while (!(A[j]<=x));
        do { i++; } while (!(A[i]>=x));
        
        if (i<j) {
            tmp=A[i];
            A[i]=A[j];
            A[j]=tmp;
        } else {
            return j;
        }
    }
}

void quicksort(int A[], int p, int r) {
    if (p<r-1) {
        int q=hoare_partition(A,p,r);
        quicksort(A,p,q+1);
        quicksort(A,q+1,r);
    }
}
