/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.4-3
 * 名称:  NONRECURSIVE-PRINT-TREE
 * 作者:  skanev
 * 语言:  c
 * 内容摘要: 非递归输出二叉树结点关键字
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
#define MAX_SIZE 10

struct tree_t {
    struct tree_t *left;
    struct tree_t *right;
    struct tree_t *parent;
    int key;
};
typedef struct tree_t tree_t;
void store(int);

void print_tree(tree_t *tree) {
    tree_t *stack[MAX_SIZE];
    int count = 0;
    
    stack[count++] = tree;
    
    while (count) {
        tree = stack[--count];
        
        store(tree->key);
        
        if (tree->right)
            stack[count++] = tree->right;
        
        if (tree->left)
            stack[count++] = tree->left;
    }
}

int keys[MAX_SIZE];
int count = 0;

void reset_storage() {
    count = 0;
}

void store(int key) {
    keys[count++] = key;
}
