/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 7-4
 * 名称:  TAIL-RECURSIVE-QUICKSORT
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: stack depth for quicksort
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

int partition(int[], int, int);

static int stack_depth=0;
static int max_stack_depth=0;

void reset_stack_depth_counter();
void increment_stack_depth();
void decrement_stack_depth();

void tail_recursive_quicksort(int A[], int p, int r) {
    increment_stack_depth();
    
    while (p<r-1) {
        int q=partition(A, p, r);
        
        if (q<(p+r)/2) {
            tail_recursive_quicksort(A, p, q);
            p=q;
        } else {
            tail_recursive_quicksort(A, q+1, r);
            r=q;
        }
    }
    
    decrement_stack_depth();
}

int partition(int A[], int p, int r) {
    int x, i, j, tmp;
    
    x=A[r-1];
    i=p;
    
    for (j=p; j<r-1; j++) {
        if (A[j]<=x) {
            tmp=A[i]; A[i]=A[j]; A[j]=tmp;
            i++;
        }
    }
    
    tmp=A[i]; A[i]=A[r-1]; A[r-1]=tmp;
    
    return i;
}

void increment_stack_depth() {
    stack_depth++;
    if (max_stack_depth<stack_depth) {
        max_stack_depth=stack_depth;
    }
}

void decrement_stack_depth() {
    stack_depth--;
}

void reset_stack_depth_counter() {
    max_stack_depth=0;
    stack_depth=0;
}
