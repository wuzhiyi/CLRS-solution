/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Chapter 2.3.1
 * 文件:     MERGE
 * 作者:     cppgp
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
int merge(int *arr, size_t p, size_t q, size_t r)
{
    int i,j,k;
    int n1=q-p+1;
    int n2=r-q;
    int *arr_l, *arr_r;
    
    assert(NULL!=arr);
    assert(p<=q && q<r);
    
    arr_l=malloc(sizeof(int)*n1);
    arr_r=malloc(sizeof(int)*n2);
    if (NULL==arr_l || NULL==arr_r) {
        /* to free a null pointer is a safe operation */
        free(arr_l);
        free(arr_r);
        return -ENOMEM;
    }
    
    /* we dont's use dummy node but to check l and r sub-array */
    for (i=0; i<n1; ++i)
        arr_l[i]=arr[p+i];
    for (j=0; j<n2; ++j)
        arr_r[j]=arr[q+j+1];
    
    for (i=0,j=0,k=p; i<n1 && j<n2; ++k) {
        if (arr_l[i]<arr_r[j]) {
            arr[k]=arr_l[i];
            ++i;
        } else {
            arr[k]=arr_r[j];
            ++j;
        }
    }
    
    /* append unused nodes */
    while (i<n1) arr[k++]=arr_l[i++];
    while (j<n2) arr[k++]=arr_r[j++];
    
    free(arr_l);
    free(arr_r);
    
    return 0;
}

int merge_sort(int *arr, size_t p, size_t r)
{
    if (p<r) {
        size_t q=(p+r)/2;
        
        if (0==merge_sort(arr,p,q) && 0==merge_sort(arr,q+1,r))
            return merge(arr,p,q,r);
        
        return -ENOMEM;
    }
    
    return 0;
}
