/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.3-7
 * 文件:     FIND
 * 作者:     qiemengdao.iteye.com
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
/*
 * 参数：按升序排列的数组，数组的起始位置，末尾位置，查找和为 key 的两个元素
 * 返回结果：若不存在和为 key 的两个元素，返回 0. 否则，返回存在的组数
 */
int find(int a[], int start, int end, int key)
{
    int i=start, j=end, num=0;   // num 是符合条件的组数
    while(1)
    {
        if (i>j)   // 输入错误，break
            break;
        if (a[i]+a[j]<key)   // 头尾元素相加<key，则头元素右移
            i++;
        else if (a[i]+a[j]>key)  // 头尾元素相加>key，则尾元素左移
            j--;
        else {   // 排除其他可能后，头尾元素相加=key,输出
            printf("%d+%d=%d\n", a[i],a[j],key);
            i++,j--;
            num++;
        }
    }
    
    return num;
}
