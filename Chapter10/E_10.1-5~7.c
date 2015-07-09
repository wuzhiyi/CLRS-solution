/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.1-5, 10.1-6, 10.1-7
 * 名称:  Double-ended queue
 * 作者:  Nastukashii
 * 语言:  c
 * 内容摘要: 双端队列实现代码
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define Max 100

//双端队列实现c
typedef struct{
    int head;
    int tail;
    int a[Max];
}Deque;

void Init_Deque(Deque *d){
    d->head = -1;
    d->tail = 0;
}

bool Empty(Deque *d){
    return d->head == -1;
}

void Push_Back(Deque *d,int key){
    if (d->head == d->tail){
        fprintf(stderr, "Deque overflow");
        exit(1);
    }
    if (d->head == -1)
        d->head = d->tail;
    d->a[d->tail] = key;
    d->tail = (d->tail + 1) % Max;
}

int Pop_Back(Deque *d){
    if (d->head == -1){
        fprintf(stderr, "Deque underflow");
        exit(1);
    }
    d->tail = (d->tail - 1+Max) % Max;
    if (d->head == d->tail)
        d->head = -1;
    return d->a[d->tail];
}

void Push_Front(Deque *d,int key){
    if (d->head == d->tail){
        fprintf(stderr, "Deque overflow");
        exit(1);
    }
    if (d->head == -1)
        d->head = d->tail;
    d->head = (d->head - 1 + Max) % Max;
    d->head = key;
}

int Pop_Front(Deque *d){
    if (d->head == -1){
        fprintf(stderr, "Deque underflow");
        exit(1);
    }
    int temp = d->a[d->head];
    d->head = (d->head + 1) % Max;
    if (d->head == d->tail)
        d->head = -1;
    return temp;
}


//两个栈实现一个队列
typedef struct{
    Deque inqueue;
    Deque dequeue;
}Like_Queue;

void Push(Like_Queue *lq,int key){
    Push_Back(&lq->inqueue, key);
}

int Pop(Like_Queue *lq){
    if (Empty(&lq->dequeue)){
        while (!Empty(&lq->inqueue)){
            int temp = Pop_Back(&lq->inqueue);
            Push_Back(&lq->dequeue, temp);
        }
    }
    return Pop_Back(&lq->dequeue);
}
