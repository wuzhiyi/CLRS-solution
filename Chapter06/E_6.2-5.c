/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 6.2-5
 * 名称:  MAX-HEAPIFY
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 维护堆的性质
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#define PARENT(i)   ((i-1)/2)
#define LEFT(i)     (2*i+1)
#define RIGHT(i)    (2*i+2)

typedef struct {
    int *nodes;
    int length;
    int heap_size;
} heap;

void max_heapify(heap A, int i)
{
    int left, right, largest, temp;
    
    while(1) {
        left=LEFT(i);
        right=RIGHT(i);
        
        if (left<A.heap_size && A.nodes[left]>A.nodes[i])
            largest=left;
        else
            largest=i;
        
        if (right<A.heap_size && A.nodes[right]>A.nodes[largest])
            largest=right;
        
        if (largest==i)
            return;
        
        temp=A.nodes[i];
        A.nodes[i]=A.nodes[largest];
        A.nodes[largest]=temp;
        
        i=largest;  // 取消recursive，在循环末尾重新定义节点i
    }
}
