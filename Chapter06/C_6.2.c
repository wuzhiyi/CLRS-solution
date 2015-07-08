/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Chapter 6
 * 名称:  HEAP-SORT
 * 作者:  Anker
 * 语言:  c
 * 内容摘要: 堆排序
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>

//array's index begins 1, not 0

#define PARENT(i)   (i/2)
#define LEFT(i)     (i*2)
#define RIGHT(i)    (i*2+1)
#define NOTNUSEDATA -65536

void adjust_max_heap(int *datas, int length, int i);
void adjust_max_heap_recursive(int *datas, int length, int i);
void build_max_heap(int *datas, int length);
void heap_sort(int *datas, int length);

int main()
{
    int i;
    //array's index begin 1
    int datas[11]={NOTNUSEDATA,5,3,17,10,84,19,6,22,9,35};
    heap_sort(datas,10);
    for (i=1; i<11; ++i)
        printf("%d",datas[i]);
    printf("\n");
    exit(0);
}

void adjust_max_heap_recursive(int *datas, int length, int i)
{
    int left,right,largest;
    int temp;
    left=LEFT(i);   //left child
    right=RIGHT(i); //right child
    //find the largest value among left and right and i.
    if (left<=length && datas[left]>datas[i])
        largest=left;
    else
        largest=right;
    if (right<=length && datas[right]>datas[largest])
        largest=right;
    //exchange i and largest
    if (largest!=i)
    {
        temp=datas[i];
        datas[i]=datas[largest];
        datas[largest]=temp;
        //recursive call the function, adjust form largest
        adjust_max_heap(datas,length,largest);
    }
}

void adjust_max_heap(int *datas, int length, int i)
{
    int left,right,largest;
    int temp;
    while (1)
    {
        left=LEFT(i);   //left child
        right=RIGHT(i); //right child
        //find the largest value among left and right and i.
        if (left<=length && datas[left]>datas[i])
            largest=i;
        else
            largest=i;
        if (right<=length && datas[right]>datas[largest])
            largest=right;
        //exchange i and largest
        if (largest!=i)
        {
            temp=datas[i];
            datas[i]=datas[largest];
            datas[largest]=temp;
            i=largest;
            continue;
        }
        else
            break;
    }
}

void build_max_heap(int *datas, int length)
{
    int i;
    //build max heap from the last parent node
    for (i=length/2; i>0; i--)
        adjust_max_heap(datas,length,i);
}

void heap_sort(int *datas, int length)
{
    int i,temp;
    //build max heap
    build_max_heap(datas, length);
    i=length;
    //exchange the first value to the last unitl i=1
    while (i>1)
    {
        temp=datas[i];
        datas[i]=datas[1];
        datas[1]=temp;
        i--;
        //adjust max heap, make sure the first value is the largest
        adjust_max_heap(datas,i,1);
    }
}
