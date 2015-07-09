/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 12-1
 * 名称:  Binary search trees with equal keys
 * 作者:  windmissing
 * 语言:  C++
 * 内容摘要: 带有相同关键字的二叉搜索树
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
/* b) 布尔标志 */
// 二叉查找树结点的结构
struct node
{
    int key;    // 关键字
    int data;   // 卫星数据
    bool b;     // 布尔标志
    node *left; // 左孩子
    node *right;// 右孩子
    node *p;    // 父结点
    node(int x):key(x),data(x),b(0),left(NULL),right(NULL),p(NULL){}
};
// 二叉查找树的结构
struct tree
{
    node *root;
    tree():root(NULL){}
};
// 二叉查找树的插入
void Tree_Insert(tree *T, node *z)
{
    // 找到要插入的位置
    node *x = T->root, *y = NULL;
    // 若x为空,x是要插入的位置，x的父是z->p
    while(x != NULL)
    {
        y = x;
        // 等式成立时，由b决定插入到哪个子树
        if(z->key == x->key)
        {
            if(x->b == 0)
                x = x->left;
            else
                x = x->right;
            // 对b取反（每次访问时布尔标志在 TRUE & FALSE 交替切换）
            x->b = !x->b;
        }
        else if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // 修改指针，注意树为空的情况
    z->p = y;
    if(y == NULL)
        T->root = z;
    else if(z->key == y->key)
    {
        if(y->b == 0)
            y->left = z;
        else y->right = z;
        y->b = !y->b;
    }
    else if(z->key < y->key)
        y->left = z;
    else y->right = z;
}


/* c) 结点列表 */
// 二叉查找树结点的结构
struct node
{
    int key;    // 关键字
    int data;   // 卫星数据
    node *next; // 指向具体相同关键字的链表
    node *left; // 左孩子
    node *right;// 右孩子
    node *p;    // 父结点
    node(int x):key(x),data(x),left(NULL),right(NULL),p(NULL),next(NULL){}
};
// 二叉查找树的结构
struct tree
{
    node *root;
    tree():root(NULL){}
};
// 二叉查找树的插入
void Tree_Insert(tree *T, node *z)
{
    // 找到要插入的位置
    node *x = T->root, *y = NULL;
    // 若x为空,x是要插入的位置，x的父是z->p
    while(x != NULL)
    {
        y = x;
        // 等式成立时，不继续插入到子树中，而是链入链表中
        if(z->key == x->key)
        {
            z->next = x->next;
            x->next = z;
            return;
        }
        else if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // 修改指针，注意树为空的情况
    z->p = y;
    if(y == NULL)
        T->root = z;
    // 等式成立时，不是插入到子树中，而是链入链表中
    else if(z->key == y->key)
    {
        z->next = y->next;
        y->next = z;
    }
    else if(z->key < y->key)
        y->left = z;
    else y->right = z;
}


/* d) 随机 */
// 二叉查找树结点的结构
struct node
{
    int key;    //关键字
    int data;   //卫星数据
    node *left; //左孩子
    node *right;//右孩子
    node *p;    //父结点
    node(int x):key(x),data(x),left(NULL),right(NULL),p(NULL){}
};
// 二叉查找树的结构
struct tree
{
    node *root;
    tree():root(NULL){}
};
// 二叉查找树的插入
void Tree_Insert(tree *T, node *z)
{
    // 找到要插入的位置
    node *x = T->root, *y = NULL;
    // 若x为空,x是要插入的位置，x的父是z->p
    while(x != NULL)
    {
        y = x;
        // 若等式成立，随机地决定插入到哪个子树中
        if(z->key == x->key)
        {
            if(rand()%2 == 0)   // 随机判断条件
                x = x->left;
            else
                x = x->right;
        }
        else if(z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }
    // 修改指针，注意树为空的情况
    z->p = y;
    if(y == NULL)
        T->root = z;
    else if(z->key == y->key)
    {
        if(rand()%2 == 0)
            x = x->left;
        else
            x = x->right;
    }
    else if(z->key < y->key)
        y->left = z;
    else y->right = z;
}
