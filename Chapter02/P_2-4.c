/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Problem 2-4
 * 文件名:   MERGE-INVERSIONS
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

int MERGE(int A[], int p, int q, int r)
{
    int i,j,k,inversions=0;
    
    int n1=q-p+1;
    int n2=r-q;
    
    int L[n1];
    int R[n2];
    
    for (i=0; i<n1; i++) L[i]=A[p+i];
    for (j=0; j<n2; j++) R[j]=A[q+j+1];
    
    for (i=0,j=0,k=p; k<=r; k++)
    {
        if (i==n1) {
            A[k]=R[j++];
        } else if (j==n2) {
            A[k]=L[i++];
        } else if (L[i]<=R[j]) {
            A[k]=L[i++];
        } else {
            A[k]=R[j++];
            inversions+=n1-i;
        }
    }
    
    return inversions;
}

int MERGE_SORT(int A[], int p, int r)
{
    if (p<r)
    {
        int inversions=0;
        int q=(p+r)/2;
        inversions+=MERGE_SORT(A,p,q);
        inversions+=MERGE_SORT(A,q+1,r);
        inversions+=MERGE(A,p,q,r);
        return inversions;
    } else {
        return 0;
    }
}
