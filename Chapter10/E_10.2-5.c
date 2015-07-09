/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.2-5
 * 名称:  Singly linked circular list-dictionary operations
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 单向循环链表实现字典操作 
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
/* 在单向循环链表中使用哨兵，用来终结 search */

#include <stdlib.h>

// 构建节点
typedef struct node_t {
    int key;
    struct node_t *next;
} node_t;

// 构建链表
typedef struct {
    struct node_t nil;
} list_t;

// 初始化链表
void init_list(list_t *list) {
    list->nil.key = 0;
    list->nil.next = &(list->nil);
}

// 摧毁链表
void destroy_list(list_t *list) {
    node_t *node = list->nil.next;
    node_t *next;
    
    while (node != &(list->nil)) {
        next = node->next;
        free(node);
        node = next;
    }
}

// insert
void insert(list_t *list, int key) {
    node_t *new = (node_t *) malloc(sizeof(node_t));
    new->key = key;
    new->next = list->nil.next;
    list->nil.next = new;
}

// 节点search操作
node_t *search(list_t *list, int key) {
    node_t *node = list->nil.next;
    
    // The trick from exercise 10.2.4
    list->nil.key = key;
    while (node->key != key) {
        node = node->next;
    }
    
    if (node == &(list->nil)) {
        return NULL;
    } else {
        return node;
    }
}

// delete
void delete(list_t *list, int key) {
    node_t *node = &(list->nil);
    
    while (node->next != &(list->nil)) {
        if (node->next->key == key) {
            node_t *to_be_deleted = node->next;
            node->next = node->next->next;
            free(to_be_deleted);
        } else {
            node = node->next;
        }
    }
}
