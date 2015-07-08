/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 9.2-3
 * 名称:  RANDOMIZED-SELECT
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: RANDOMIZED-SELECT循环结构
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdlib.h>

static int tmp;
#define EXCHANGE(a,b) { tmp=a; a=b; b=tmp; }

int randomized_partition(int *A, int p, int r);

int randomized_select(int *A, int p, int r, int i)
{
    while (p<r-1)
    {
        int q = randomized_partition(A, p, r);
        int k = q-p;
        
        if (i == k) {
            return A[q];
        } else if (i < k) {
            r = q;
        } else {
            p=q+1;
            i=i-k-1;
        }
    }
    
    return A[p];
}

int partition(int *A, int p, int r)
{
    int x, i, j;
    
    x=A[r-1];
    i=p;
    
    for (j=p; j<r-1; j++)
    {
        if (A[j]<x) {
            EXCHANGE(A[i], A[j]);
            i++;
        }
    }
    
    EXCHANGE(A[i], A[r-1]);
    
    return i;
}

int randomized_partition(int *A, int p, int r)
{
    int pivot=rand()%(r-p)+p;
    EXCHANGE(A[pivot], A[r-1]);
    return partition(A, p, r);
}
