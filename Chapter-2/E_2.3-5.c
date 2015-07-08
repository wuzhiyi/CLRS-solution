/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.3-5
 * 文件:     BINARY-SEARCH
 * 作者:     skanev
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
int binary_search(int A[], int length, int v)
{
    /* 初始化 */
    int low=0;
    int high=length;
    
    int mid;
    while (low<high)    // 判断数组是否为 NIL
    {
        mid=(low+high)/2;   // 若为非空数组，取中点
        
        if (A[mid]==v)
            return mid;
        else if (A[mid]<v)   // 中点比 key 小，取右半部分
            low=mid+1;
        else   // 否则（中点比 key 大），取左半部分
            high=mid;
    }
    
    return -1;
}
