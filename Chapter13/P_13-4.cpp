/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 13-4
 * 名称:  Treap树
 * 作者:  Microgoogle
 * 语言:  C++
 * 内容摘要: Treap树
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node_t* Node;
typedef struct treap_t* Treap;

//构造结点
struct node_t
{
    Node left;      //左节点
    Node right;     //右节点
    int priority;   //优先级
    int key;        //存储的关键字
};

//构造树
struct treap_t
{
    Node root;
};

//左旋转
void rotate_left(Node* node)
{
    Node x = (*node)->right;
    (*node)->right = x->left;
    x->left = *node;
    *node = x;
}

//右旋转
void rotate_right(Node* node)
{
    Node x = (*node)->left;
    (*node)->left = x->right;
    x->right = *node;
    *node = x;
}

//插入操作
void treap_insert(Node* root, int key, int priority)
{
    //根为NULL，则直接创建此结点为根结点
    if (*root == NULL)
    {
        *root = (Node)malloc(sizeof(struct node_t));
        (*root)->left = NULL;
        (*root)->right = NULL;
        (*root)->priority = priority;
        (*root)->key = key;
    }
    //向右插入结点
    else if (key < (*root)->key)
    {
        treap_insert(&((*root)->left), key, priority);
        if ((*root)->left->priority < (*root)->priority)
            rotate_right(root);
    }
    //向左插入结点
    else
    {
        treap_insert(&((*root)->right), key, priority);
        if ((*root)->right->priority < (*root)->priority)
            rotate_left(root);
    }
}

//删除操作
void treap_delete(Node* root, int key)
{
    if (*root != NULL)
    {
        if (key < (*root)->key)
            treap_delete(&((*root)->left), key);
        else if (key > (*root)->key)
            treap_delete(&((*root)->right), key);
        else
        {
            //左右孩子都为空不用单独写出来
            if ((*root)->left == NULL)
                *root = (*root)->right;
            else if ((*root)->right == NULL)
                *root = (*root)->left;
            else
            {
                //先旋转，然后再删除
                if ((*root)->left->priority < (*root)->right->priority)
                {
                    rotate_right(root);
                    treap_delete(&((*root)->right), key);
                }
                else
                {
                    rotate_left(root);
                    treap_delete(&((*root)->left), key);
                }
            }
        }
    }
}

//中序遍历
void in_order_traverse(Node root)
{
    if (root != NULL)
    {
        in_order_traverse(root->left);
        printf("%d\t", root->key);
        in_order_traverse(root->right);
    }
}

//计算树的高度
int depth(Node node)
{
    if(node == NULL)
        return -1;
    int l = depth(node->left);
    int r = depth(node->right);
    
    return (l < r)?(r+1):(l+1);
}

int main()
{
    Treap treap = (Treap)malloc(sizeof(struct treap_t));
    treap->root = NULL;
    int i = 0;
    
    srand(time(0));
    
    for (i = 0; i < 100; i++)
        treap_insert(&(treap->root), i, rand());
    in_order_traverse(treap->root);
    printf("\n高度：%d\n", depth(treap->root));
    
    printf("---分割线---\n");
    
    for (i = 23; i < 59; i++)
        treap_delete(&(treap->root), i);
    in_order_traverse(treap->root);
    printf("\n高度：%d\n", depth(treap->root));
    return 0;
}
