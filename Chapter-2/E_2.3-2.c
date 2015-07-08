/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.3-2
 * 名称:     MERGE
 * 作者:     skanev
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

void merge(int A[], int p, int q, int r) {
    int i,j,k;
    
    int n1=q-p+1;
    int n2=r-q;
    
    int L[n1];
    int R[n2];
    
    /* 将子数组 A[p..q] 复制到 L[1..n1] */
    for (i=0; i<n1; i++)
        L[i]=A[p+i];
    /* 将子数组 A[q+1..r] 复制到 R[1..n2] */
    for (j=0; j<n2; j++)
        R[j]=A[q+j+1];
    
    /* 从已排序数组中，取较小元素赋值给 A[k]，并删除已取元素 */
    for (i=0,j=0,k=p; k<=r; k++) {
        if (i==n1) {
            A[k]=R[j++];
        } else if (j==n2) {
            A[k]=L[i++];
        } else if (L[i]<=R[j]) {
            A[k]=L[i++];
        } else {
            A[k]=R[j++];
        }
    }
}

void merge_sort(int A[], int p, int r) {
    if (p<r) {
        int q=(p+r)/2;
        merge_sort(A, p, q);
        merge_sort(A, q+1, r);
        merge(A, p, q, r);
    }
}
