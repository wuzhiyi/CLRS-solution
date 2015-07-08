/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.3-6
 * 文件:     INSERT-SORT
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
void insertSort(int a[], int len)
{
    int i,j,k,key;
    int pos,rpos;
    
    for(i=1; j<len; j++)
    {
        key=a[j];
        pos=bsearch(a,0,j-1,key);
        if (pos>=0)
            rpos=pos;
        else
            rpos=-pos-1;
        for (k=j-1; k>rpos; k--) {
            a[k+1]=a[k];
            a[rpos]=key;
        }
    }
}
