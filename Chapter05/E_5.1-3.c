/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 5.1-3
 * 名称:  BIASE-RANDOM(a,b)
 * 作者:  facingwaller
 * 语言:  c
 * 内容摘要: 有偏输出0或1
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int biaseRandom()
{
    int i=random(3);
    if (i>=1) return 1;
    else return 0;
}

int t5_1_3()
{
    int j1=0, j2=0;
    while (1)
    {
        j1=biaseRandom();
        j2=biaseRandom();
        if (j1+j2!=1) {
            continue;
        }
        if (j1==1) return 1;
        else return 0;
    }
}

/* 测试代码 */
int main()
{
    int j=0,
        i0=0,
        i1=0;
    for (;j<500;j++) {
        if (t5_1_3()==0) i0++;
        else i1++;
    }
    
    printf("i0=%d,i1=%d", i0,i1);
    
    return 0;
}
