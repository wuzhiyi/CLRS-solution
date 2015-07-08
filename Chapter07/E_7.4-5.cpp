/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 7.4-5
 * 名称:  MODIFIED-QUICKSORT
 * 作者:  windmissing
 * 语言:  C++
 * 内容摘要: 利用插入排序改善快排
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
// 利用插入排序改善快排
int k=4;

// 划分
int Partition(int *A, int p, int r)
{
    // 选择A[r]作为主元
    int x=A[r];
    int i=p-1, j;
    bool flag=0;
    
    for (j=p; j<r; j++)
    {
        // 小于主元的放在左边
        if (A[j]<x || (A[j]==x && flag))
        {
            i++;
            // 把大于主元的交换到右边
            swap(A[i],A[j]);
            if (A[j]==x) flag=!flag;
        }
    }
    
    swap(A[i+1],A[r]);
    // 返回最终主元的位置
    
    return i+1;
}

// 快速排序
void QuickSort(int *A, int p, int r)
{
    // 长度小于k的子数组不排序
    if (r-p>=k)
    {
        // 以某个主元为标准，把数组分为两部分，左边都比主元小，右边都比主元大
        int q=Partition(A,p,r);
        // 分别对左边和右边排序
        QuickSort(A,p,q-1);
        QuickSort(A,q+1,r);
    }
}

// 插入排序
void InsertSort(int *A, int p, int r)
{
    int i, j;
    for (i=p+1; i<=r; i++)
    {
        int temp=A[i];
        j=i;
        while (A[j-1]>temp) {
            A[j]=A[j-1];
            j--;
        }
        A[j]=temp;
    }
}

void Sort(int *A, int p, int r)
{
    // 先进行粗粒度的快排
    QuickSort(A,p,r);
    // 逐个进行插入排序
    InsertSort(A,p,r);
}
