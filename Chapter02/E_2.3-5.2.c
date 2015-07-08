/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.3-5
 * 文件:     BSEARCH & RBSEARCH
 * 作者:     iteye
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

/* 迭代 */
int BSEARCH(int a[], int low, int high, int key)
{
    int mid=0;
    while (low<=high) {// 注意循环条件 low<=high
        mid=low+(high-low)/2;
    if (a[mid]==key)
        return mid;
    else if (a[mid]>key)
        high=mid-1;
    else
        low=mid+1;
    }
    
    return -(low+1);
}

/* 递归 */
int RBSEARCH(int a[], int low, int high, int key)
{
    if (low>high)
        return -(low+1);
    int mid=low+(high-low)/2;
    if (a[mid]==key)
        return mid;
    else if (a[mid]>key)
        return RBSEARCH(a, low, mid-1, key);
    else
        return RBSEARCH(a, mid+1, high, key);
}
