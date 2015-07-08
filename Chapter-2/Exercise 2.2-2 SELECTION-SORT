/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.2-2
 * 文件名:   SELECTION-SORT
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
void selction_sort(int *arr, size_t size)
{
    int i, j, min;
    
    assert(NULL!=arr);
    
    for (i=0; i<size; ++i) {
        min=i;
        for (j=i+1; j<size; ++j) {
            if (arr[j]<arr[min])
                min=j;
        }
        /* exchanges */
        if (min!=i) {
            arr[i]=arr[i]^arr[min];
            arr[min]=arr[min]^arr[i];
            arr[i]=arr[i]^arr[min];
        }
    }
}
