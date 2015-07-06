/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Problem 2-1
 * 文件名:   INSERT-MERGE-SORT & SELECT-MERGE-SORT
 * 作者:     skanev
 * 语言:     c
 * 内容摘要: 
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150702       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdlib.h>
#include <string.h>

#define INSERTION_SORT_TRESHOLD 20
#define SELECTION_SORT_TRESHOLD 15

/* 归并排序 */
void merge(int A[], int p, int q, int r)
{
    int i,j,k;
    
    int n1=q-p+1;
    int n2=r-q;
    
#ifdef MERGE_HEAP_ALLOCTION
    /* 在内存的动态存储区中分配 n 块长度为 size 字节的连续区域，每一位都初始化为零，返回首地址 */
    int *L=calloc(n1, sizeof(int));
    int *R=calloc(n2, sizeof(int));
#else
    int L[n1];
    int R[n2];
#endif
    /* 原型 void *memcpy(void *dest, const void *src, size_t n); */
    /* 由 src 指向地址为起始地址的连续 n 个字节的数据复制到以 destin 指向地址为起始地址空间内 */
    /* 返回值为一个指向 dest 的指针 */
    memcpy(L, A+p, n1*sizeof(int));
    memcpy(R, A+q+1, n2*sizeof(int));
    
    /* 从左到右分别比较大小，取较小者赋值给 A[k]，合并，并在等待数组中删除 */
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
        }
    }
    
#ifdef MERGE_HEAP_ALLOCATION
    /* void free( *FirstByte):将之前分配的空间还给程序或操作系统，也就是释放该内存 */
    free(L);
    free(R);
#endif
}

void merge_sort(int A[], int p, int r) {
    if (p<r)
    {
        int q=(p+r)/2;
        merge_sort(A,p,q);
        merge_sort(A,q+1,r);
        merge(A,p,q,r);
    }
}

/* 插入排序 */
void insertion_sort(int A[], int p, int r)
{
    int i,j,key;
    
    for (j=p+1; j<=r; j++)
    {
        i=j-1;
        key=A[i];   // 先初始化 i
        while (i>=p && A[i]>key)
        {
            A[i+1]=A[i];
            i=i-1;
        }
        A[i+1]=key;
    }
}

/* 选择排序 */
void selection_sort(int A[], int p, int r)
{
    int min, temp;
    for (int i=p; i<r; i++) {
        min=i;
        for (int j=i+1; i<=r; j++)
            if (A[j]<A[min])
                min=j;
        temp=A[i];
        A[i]=A[min];
        A[min]=temp;
    }
}

/* 插入-归并排序 */
void mixed_sort_insertion(int A[], int p, int r)
{
    if (p>=r) return;
    
    if (r-p<INSERTION_SORT_TRESHOLD) {
        insertion_sort(A,p,r);
    } else {
        int q=(p+r)/2;
        mixed_sort_insertion(A,p,q);
        mixed_sort_insertion(A,q+1,r);
        merge(A,p,q,r);
    }
}

/* 选择-归并排序 */
void mixed_sort_selection(int A[], int p, int r)
{
    if (p>=r) return;
    
    if (r-p<SELECTION_SORT_TRESHOLD) {
        selection_sort(A,p,r);
    } else {
        int q=(p+r)/2;
        mixed_sort_selection(A,p,q);
        mixed_sort_selection(A,q+1,r);
        merge(A,p,q,r);
    }
}
