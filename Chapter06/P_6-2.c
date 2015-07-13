/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 6-2
 * 名称:  D-ARY-HEAP
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 对d叉堆的分析
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PARENT(i,d)     ((i-1)/d)
#define CHILD(i,c,d)    (3*i+c+1)

typedef struct {
    int *elements;
    int d;
    int heap_size;
    int length;
} heap_t;

void max_heapify(heap_t *heap, int i)
{
    int largest=i;
    
    for (int k=0; k<heap->d; k++) {
        int child=CHILD(i,k,heap->d);
        if (child<heap->heap_size && heap->elements[child]>heap->elements[largest])
            largest=child;
    }
    
    if (largest!=i)
    {
        int tmp=heap->elements[i];
        heap->elements[i]=heap->elements[largest];
        heap->elements[largest]=tmp;
        
        max_heapify(heap,largest);
    }
}

int extract_max(heap_t *heap)
{
    int max=heap->elements[0];
    heap->elements[0]=heap->elements[heap->heap_size-1];
    heap->heap_size--;
    max_heapify(heap,0);
    return max;
};

void increase_key(heap_t *heap, int i, int key)
{
    if (key<heap->elements[i]) {
        fprintf(stderr,"new key is smaller than current key\n");
        exit(0);
    }
    
    while (i>0 && heap->elements[PARENT(i,heap->d)]<key) {
        heap->elements[i]=heap->elements[PARENT(i,heap->d)];
        i=PARENT(i,heap->d);
    }
    
    heap->elements[i]=key;
}

void insert(heap_t *heap, int key)
{
    heap->heap_size++;
    heap->elements[heap->heap_size-1]=INT_MIN;
    increase_key(heap,heap->heap_size-1,key);
}
