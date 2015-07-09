/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 10-2
 * 名称:  Linked List & Mergeable Heap
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 利用链表实现可合并堆
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/
#include <stdlib.h>
#include <stdarg.h>

/////////////////////////////////////////////////////////////////////////////
// List operations
/////////////////////////////////////////////////////////////////////////////

// 链表结构
struct list_t {
    int key;
    struct list_t *next;
};

// 链表结构声明
typedef struct list_t list_t;

// 插入排序
list_t *insert_sorted(list_t *list, int key) {
    list_t *new = malloc(sizeof(list_t));
    new->key = key;
    
    if (!list || key < list->key) {
        new->next = list;
        return new;
    }
    
    list_t *l = list;
    while (l->next && l->next->key < key) {
        l = l->next;
    }
    
    new->next = l->next;
    l->next = new;
    
    return list;
}

// 删除关键字
list_t *delete_key(list_t *list, int key) {
    list_t *match;
    while (list && list->key == key) {
        match = list;
        list = list->next;
        free(match);
    }
    
    if (!list) {
        return NULL;
    }
    
    list_t *node = list;
    while (node->next) {
        if (node->next->key == key) {
            match = node->next;
            node->next = match->next;
            free(match);
        } else {
            node = node->next;
        }
    }
    
    return list;
}

list_t *prepend(list_t *list, int key) {
    list_t *new = malloc(sizeof(list_t));
    
    new->key = key;
    new->next = list;
    
    return new;
}

// 找到最小值
int find_min(list_t *list) {
    int min = list->key;
    list = list->next;
    
    while (list) {
        if (list->key < min) {
            min = list->key;
        }
        list = list->next;
    }
    
    return min;
}

// 链表合并
list_t *link_together(list_t *a, list_t *b) {
    list_t *result;
    
    if (!a) {
        result = b;
    } else {
        result = a;
        while (a->next) {
            a = a->next;
        }
        a->next = b;
    }
    
    return result;
}

// 归并排序
list_t *merge_sorted(list_t *a, list_t *b) {
    list_t dummy;
    list_t *new = &dummy;
    
    while (a && b) {
        if (a->key < b->key) {
            new->next = a;
            a = a->next;
            new = new->next;
        } else {
            new->next = b;
            b = b->next;
            new = new->next;
        }
    }
    
    if (a) {
        new->next = a;
    } else {
        new->next = b;
    }
    
    return dummy.next;
}

/////////////////////////////////////////////////////////////////////////////
// 1. Mergreable heaps with sorted list
/////////////////////////////////////////////////////////////////////////////

typedef struct {
    list_t *head;
} heap1;

heap1 *make_heap1() {
    heap1 *result = malloc(sizeof(heap1));
    result->head = NULL;
    return result;
}

void insert1(heap1 *heap, int key) {
    heap->head = insert_sorted(heap->head, key);
}

int minimum1(heap1 *heap) {
    return heap->head->key;
}

int extract_min1(heap1 *heap) {
    list_t *head = heap->head;
    int result = head->key;
    heap->head = head->next;
    free(head);
    return result;
}

heap1 *union1(heap1 *ha, heap1 *hb) {
    heap1 *result = malloc(sizeof(heap1));
    result->head = merge_sorted(ha->head, hb->head);
    
    free(ha);
    free(hb);
    
    return result;
}

/////////////////////////////////////////////////////////////////////////////
// 2. Mergreable heaps with unsorted lists
/////////////////////////////////////////////////////////////////////////////

typedef struct {
    list_t *head;
} heap2;

heap2 *make_heap2() {
    heap2 *result = malloc(sizeof(heap2));
    result->head = NULL;
    return result;
}

void insert2(heap2 *heap, int key) {
    heap->head = prepend(heap->head, key);
}

int minimum2(heap2 *heap) {
    return find_min(heap->head);
}

int extract_min2(heap2 *heap) {
    int min = minimum2(heap);
    heap->head = delete_key(heap->head, min);
    return min;
}

heap2 *union2(heap2 *ha, heap2 *hb) {
    heap2 *result = make_heap2();
    result->head = link_together(ha->head, hb->head);
    
    free(ha);
    free(hb);
    
    return result;
}
