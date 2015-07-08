/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 7-1
 * 名称:  HOARE-PARTITION
 * 作者:  alan-forever
 * 语言:
 * 内容摘要: Hoare划分
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
int hoare_partition(int A[], int p, int r) {
    int x=A[p],
        i=p,
        j=r;
    
    while(i < j) {
        while(i<j && A[j]>x)
            j--;
        A[i]=A[j];
        while(i<j && A[i]<x)
            i++;
        A[j]=A[i];
    }
    
    A[i]=x;
    return j;
}

void hoare_quick_sort(int A[], int p, int r) {
    if (p<r) {
        int q=hoare_artition(A,p,r);
        hoare_quick_sort(A,p,q-1);
        hoare_quick_sort(A,q+1,r);
    }
}
