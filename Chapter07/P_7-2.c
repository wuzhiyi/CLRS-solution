/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 7-2
 * 名称:  EQUAL-VALUE-PARTITION
 * 作者:  clrs.skanev.com
 * 语言:  c
 * 内容摘要: quicksort with equal element value
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdlib.h>

#define EXCHANGE(a,b) tmp=a; a=b; b=tmp;

typedef struct {
    int q;
    int t;
} pivot_t;

pivot_t partition(int[], int, int);
pivot_t randomized_partition(int[], int, int);

void quicksort(int A[], int p, int r) {
    if (p<r-1) {
        pivot_t pivot=randomized_partition(A, p, r);
        quicksort(A, p, pivot.q);
        quicksort(A,pivot.t, r);
    }
}

pivot_t randomized_partition(int A[], int p, int r) {
    int i=rand()%(r-p)+p,
        tmp;
    
    EXCHANGE(A[i], A[r-1]);
    
    return partition(A, p, r);
}

pivot_t partition(int A[], int p, int r) {
    int x=A[r-1],
        q=p,
        t,
        tmp;
    
    for (int i=p; i<r-1; i++) {
        if (A[i]<x) {
            EXCHANGE(A[q], A[i]);
            q++;
        }
    }
    
    for (t=q; t<r && A[t]==x; t++);
    
    for (int i=r-1; i>=t; i--) {
        if (A[i]==x) {
            EXCHANGE(A[t], A[i]);
            t++;
        }
    }
    
    pivot_t result={q, t};
    return result;
}
