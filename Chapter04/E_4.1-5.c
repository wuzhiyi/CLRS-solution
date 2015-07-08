/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 4.1-5
 * 名称:  MAXIMUM-SUBARRAY(linear time)
 * 作者:  clrs.skanev.com
 * 语言:  c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <limits.h>

typedef struct {
    unsigned left;
    unsigned right;
    int sum;
}; max_subarray;

max_subarray find_maximum_subarray(int A[], unsigned low, unsigned high)
{
    max_subarray suffixes[high-low];
    
    suffixes[0].left=low;
    suffixes[0].right=low+1;
    suffixes[0].sum=A[low];
    
    for (int i=low+1; i<high; i++)
    {
        if (suffixes[i-1].sum<0) {
            suffixes[i].left=i;
            suffixes[i].right=i+1;
            suffixes[i].sum=A[i];
        } else {
            max_subarray *previous=&suffixes[i-1];
            suffixes[i].left=previous->left;
            suffixes[i].right=i+1;
            suffixes[i].sum=previous->sum+A[i];
        }
    }
    
    max_subarray *max=&suffixes[0];
    
    for (int i=low+1; i<high; i++) {
        if (max->sum<suffixes[i].sum) {
            max=&suffixes[i];
        }
    }
    
    return *max;
}
