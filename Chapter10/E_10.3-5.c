/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.3-5
 * 名称:  COMPACTIFY-LIST
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 使双向链表保持紧凑 
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int list_t;
typedef int obj_t;

int empty_list = -1;

int   prev[MAX_SIZE];
int   next[MAX_SIZE];
obj_t keys[MAX_SIZE];

int free_list;

// 初始化存储
void init_storage() {
    int i;
    for (i = 0; i < MAX_SIZE - 1; i++)
        next[i] = i + 1;
    
    next[i] = -1;
    free_list = 0;
}

// ALLOCATE-OBJECT
list_t allocate_object() {
    if (free_list == -1) {
        fprintf(stderr, "Storage depleted\n");
        exit(1);
    }
    
    list_t new = free_list;
    free_list = next[free_list];
    return new;
}

// FREE-OBJECT
void free_object(list_t list) {
    next[list] = free_list;
    free_list = list;
}

// 构建list
list_t cons(obj_t key, list_t list) {
    list_t new = allocate_object();
    
    next[new] = list;
    prev[new] = empty_list;
    keys[new] = key;
    
    if (list != empty_list) {
        prev[list] = new;
    }
    
    return new;
}

// 删除list
void delete(list_t list) {
    if (prev[list] != empty_list) {
        next[prev[list]] = next[list];
    }
    
    if (next[list] != empty_list) {
        prev[next[list]] = prev[list];
    }
    
    free_object(list);
}

obj_t get(list) {
    if (list == empty_list) return -1;
    return keys[list];
}

list_t next_obj(list) {
    if (list == empty_list) return -1;
    return next[list];
}

// COMPACTIFY-LIST
list_t compatify_list(list_t list) {
    list_t left, right, i;
    
    if (free_list == empty_list) {
        return list;
    }
    
    i = free_list;
    while (i != empty_list) {
        prev[i] = -2;
        i = next[i];
    }
    
    left  = 0;
    right = MAX_SIZE - 1;
    while (1) {
        while (prev[left] != -2)
            left++;
        
        while (prev[right] == -2)
            right--;
        
        if (left >= right) break;
        
        prev[left] = prev[right];
        next[left] = next[right];
        keys[left] = keys[right];
        
        next[right] = left;
        
        right--;
        left++;
    }
    
    right++;
    
    for (int i = 0; i < right; i++) {
        if (prev[i] >= right) {
            prev[i] = next[prev[i]];
        }
        
        if (next[i] >= right) {
            next[i] = next[next[i]];
        }
    }
    
    if (list >= right) {
        list = next[list];
    }
    
    for (i = right; i < MAX_SIZE - 1; i++) {
        next[i] = i+1;
    }
    next[i] = -1;
    
    free_list = right;
    
    return list;
}
