/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:     Exercise 2.2-2
 * 文件名:   SLECTION-SORT
 * 作者:     blog.csdn.net/pang123hui
 * 语言:     c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void selction_sort(int in[], int count)
{
    int i=0;
    int j=0;
    int min_count=0;
    
    for (i=0; i<count-1; i++)
    {
        min_count=i;
        /* 寻找剩余数值的最小值 */
        for (j=i+1; j<count; j++){
            if (in[j]<in[min_count]) {
                min_count=j;
            }
        }
        /* 不等时交换 */
        if (i!=min_count)
        {
            j=in[min_count];
            in[min_count]=in[i];
            in[i]=j;
        }
    }
}

int main(void)
{
    int i=0;
    int arr[10]={0};
    
    /* 随机数发生器的初始化函数 */
    srand(time(NULL));
    
    printf("原数组为:\n");
    /* 随机赋值 */
    for (i=0; i<10; i++){
        printf("%5d", arr[i]);
    }
    printf("\n");
    
    /* selection sort */
    selection_sort(arr, 10);
    
    printf("排序数组为:\n");
    for (i=0; i<10; i++) {
        printf("%5d", arr[i]);
    }
    printf("\n");
    
    getchar();
    return 0;
}
