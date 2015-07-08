/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目: Chapter 7.3
 * 名称:  RANDOMIZED-QUICKSORT
 * 作者:  alan-forever
 * 语言:
 * 内容摘要: 快速排序随机化版本
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
int RANDOMIZED_PARTITION(int A[], int p, int r)
{
    int i=p+rand()%(r-p+1);
    int temp=A[r];
    A[r]=A[i];
    A[i]=temp;
    return PARTITION(A,p,r);
}

int PARTITION(int A[], int p, int r)
{
    int x=A[r];
    int i=p-1;
    int j;
    for (j=p; j<=r-1; j++)
    {
        if (A[j]<=x)
        {
            i++;
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }
    }
    int temp=A[i+1];
    A[i+1]=A[r];
    A[r]=temp;
    return i+1;
}

void RANDOMIZED_QUICKSORT(int A[], int p, int r)
{
    if (p<r)
    {
        int q=randomized_PARTITION(A,p,r);
        RANDOMIZED_QUICKSORT(A,p,q-1);
        RANDOMIZED_QUICKSORT(A,q+1,r);
    }
}
