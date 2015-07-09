/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.2-2
 * 名称:  Singly linked list-stack
 * 作者:  alan-forever
 * 语言:  c
 * 内容摘要: 单链表实现栈
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode * next;
}ListNode;

typedef struct {
    ListNode * top;
}Stack;

void list_insert(ListNode *l , int x);

void print_list(ListNode *l);

int stack_empty(Stack *S);

void push(Stack *S, int x);

int pop(Stack *S);

int main(){
    int i, num;
    Stack * S;
    S = (Stack *)malloc(sizeof(Stack));
    S->top = (ListNode *)malloc(sizeof(ListNode));
    
    for(i = 1; i <= 5; i++){
        scanf("%d", &num);
        push(S, num);
    }
    
    //printf("%d\n", stack_empty(S));
    //print_list(S->top);
    
    for(i = 1; i<= 5; i++)
        printf("%d ", pop(S));
    printf("\n");
    
    return 0;
}

void list_insert(ListNode *l, int x){
    ListNode * p;
    p = (ListNode *)malloc(sizeof(ListNode));
    p->value = x;
    if(l->next == NULL){
        l->next = p;
        p->next = NULL;
    }
    else{
        p->next = l->next;
    }
    l->next = p;
}

void print_list(ListNode *l){
    ListNode * p = l->next;
    while(p != NULL){
        printf("%d ", p->value);
        p = p->next;
    }
    printf("\n");
}


int stack_empty(Stack *S){
    if(S->top->next == NULL)
        return 1;
    else
        return 0;
}

void push(Stack *S, int x){
    list_insert(S->top, x);
}

int pop(Stack *S){
    if(stack_empty(S)){
        printf("underflow\n");
        return ;
    }
    else{
        ListNode *p = S->top->next;
        int x = p->value;
        S->top->next = p->next;
        free(p);
        return x;
    }
}
