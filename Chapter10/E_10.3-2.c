/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.3-2
 * 名称:  Single Array
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 单数组实现ALLOCATE-OBJECT和FREE-OBJECT
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 3

typedef int list_t;
typedef int obj_t;

int empty_list = -1;
int cells[MAX_SIZE * 3];
int free_list;

#define NEXT(i) cells[(i) + 1]
#define PREV(i) cells[(i) + 2]
#define KEY(i)  cells[i]

// 初始化存储
void init_storage() {
    int i;
    for (i = 0; i < (MAX_SIZE - 1) * 3; i += 3)
        NEXT(i) = i + 3;
    
    NEXT(i) = -1;
    free_list = 0;
}

// ALLOCATE-OBEJCT
list_t allocate_object() {
    if (free_list == -1) {   // 如果自由表为空，表明单数组已满
        fprintf(stderr, "Storage depleted\n");
        exit(1);
    }
    
    // 插入对象
    list_t new = free_list;
    free_list = NEXT(free_list);
    return new;
}

// 释放对象
void free_object(list_t list) {
    NEXT(list) = free_list;
    free_list = list;
}

list_t cons(obj_t key, list_t list) {
    list_t new = allocate_object();
    
    NEXT(new) = list;
    PREV(new) = empty_list;
    KEY(new) = key;
    
    if (list != empty_list) {
        PREV(list) = new;
    }
    
    return new;
}

// 删除链表
void delete(list_t list) {
    if (PREV(list) != empty_list) {
        NEXT(PREV(list)) = NEXT(list);
    }
    
    if (NEXT(list) != empty_list) {
        PREV(NEXT(list)) = PREV(list);
    }
    
    free_object(list);
}

// 返回key
obj_t get(list) {
    if (list == empty_list) return -1;
    return KEY(list);
}

// 返回list.next
list_t next(list) {
    if (list == empty_list) return -1;
    return NEXT(list);
}
