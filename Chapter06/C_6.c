/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Chapter 6
 * 名称:  HEAP-SORT
 * 作者:  Anker
 * 语言:  c
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
/* 递归形式递归 */
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
        largest=i;
    if (right<=length && datas[right]>datas[largest])
        largest=right;
    //exchange i and largest
    if (largest!=i)
    {
        temp=datas[i];
        datas[i]=datas[largest];
        datas[largest]=temp;
        //recursive call the function, adjust from largest
        adjust_max_heap(datas,length,largest);
    }
}

/* 非递归形式调整 */
void adjust_max_heap(int *datas, int length, int i)
{
    int left,right,largest;
    int temp;
    while(1)
    {
        left=LEFT(i);   //left child
        right=RIGHT(i); //right child
        //find the largest value among left and right and i.
        if (left<=length && datas[left]>datas[i])
            largest=left;
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

/* 创建堆 */
void build_max_heap(int *datas, int length)
{
    int i;
    //build max heap from the last parent node
    for (i=length/2; i>0; i--)
        adjust_max_heap(datas, length, i);
}

/* 堆排序 */
void heap_sort(int *datas, int length)
{
    int i,temp;
    //build max heap
    build_max_heap(datas, length);
    i=length;
    //exchange the first value to the last unit1 i=1
    while (i>1)
    {
        temp=datas[i];
        datas[i]=datas[1];
        datas[1]=temp;
        i--;
        //adjust max heap, make sure the first value is the largest
        adjust_max_heap(datas, i, 1);
    }
}
