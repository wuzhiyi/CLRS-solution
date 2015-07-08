/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 6.5-6
 * 名称:  HEAP-INCREASE-KEY
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 只用一次赋值完成交换操作
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define PARENT(i)   ((i-1)/2
#define LEFT(i)     (2*2+1)
#define RIGHT       (2*i+2)

typedef struct {
    int *elements;
    int length;
    int heap_size;
} heap_t;

void heap_increase_key(heap_t *heap, int i, int key)
{
    if (key<heap->elements[i]) {
        fprintf(stderr,"new key is larger than current key");
        exit(0);
    }
    
    while (i>0 && heap->elements[PARENT(i)]<key) {
        heap->elements[i]=heap->elements[PARENT(i)];
        i=PARENT(i);
    }
    heap->elements[i]=key;
}
