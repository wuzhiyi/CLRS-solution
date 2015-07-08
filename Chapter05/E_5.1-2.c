/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 5.1-2
 * 名称:  RANDOM(a,b)
 * 作者:  www.cnblogs.com/facingwaller
 * 语言:  c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define random(x) (rand()%x)

int t5_1_2(int low, int high)
{
    int i=0;
    int count=0;
    double j=log(high-low+1)/log(2);
    
    if (j-(int)j>0) {
        j++;
    }
    
    while(1) {
        count=0;
        for (i=0; i<j; i++) {
            count+=random(2)*pow(2,i);
        }
        if (low+count<=high) {
            break;
        }
    }
    
    return low+count;
}

int main()
{
    int j=0;
    
    for (; j<11; j++)
    {
        int a1=t5_1_2(1,4);
        int a2=t5_1_2(11,14);
        printf("between %d and %d: %d\n",a1,a2,t5_1_2(a1,a2));
    }
    
    return 0;
}
