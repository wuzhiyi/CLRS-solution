/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Chapter 4
 * 名称:  MAX-SUM
 * 作者:  www.biancneg.cn
 * 语言:  c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>

void MaxSum(int array[], unsigned int len)
{
    if (array==NULL || len<=0)
        return;
    
    int curSum=0, maxSum=0;
    int i=0;
    for (i=0; i<len; i++)
    {
        curSum+=array[i];    // 累加
        
        if (curSum<0)        // 当前和小于 0，重置为 0
            curSum=0;
        if (curSum>maxSum)   // 当前和大于最大和，则重置最大和
            maxSum=curSum;
    }
    
    if (maxSum==0)           // 最大和依然为 0，说明数组中所有元素都为负值
    {
        maxSum=array[0];
        for (i=1; i<len; i++) {
            if (array[i]>maxSum) {
                maxSum=array[i];
            }
        }
    }
    
    printf("maxSum: %d\n", maxSum);
}
