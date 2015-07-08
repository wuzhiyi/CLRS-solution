/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Problem 2-1
 * 文件名:   INSERT-MERGE-SORT & SELECT-MERGE-SORT
 * 作者:     iteye
 * 语言:     c
 * 内容摘要: mergeSort(A, p, r)
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150706       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdio.h>

void mergeSort(int A[], int p, int r)
{
    if (r-p<=6) {   // 这里的 r-p+1<=7, 即 r-p<=6，k 值为 7
        return insertSort(A,p,r);
    } else {
        int q=(p+r)/2;
        mergeSort(A,p,q);
        mergeSort(A,q+1,r);
        mergeSort(A,p,q,r);   // ???多一个参数
    }
}

/* 插入排序 */
void insertSort(int A[], int p, int r)
{
    int i,j,key;
    
    for (j=p+1; j<=r; j++) {
        key=A[j];
        i=j-1;
        while (i>=p && A[i]>key) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}


/* 插入排序变形 */
void insertSort2(int A[], int p, int r)
{
    int i,j;
    for (i=p; i<r; i++)
        for (j=i+1; j>p&&A[j-1]>A[j]; j--)
            swap(A,j,j-1);   // 交换数组 A 中的 j 和 j-1 位置处的值
}
