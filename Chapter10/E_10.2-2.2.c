/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.2-2
 * 名称:  Singly linked list-stack
 * 作者:  windmissing
 * 语言:  c
 * 内容摘要: 单链表实现栈
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
 **************************************************************/
//结点
struct node
{
    node *pre;//为了方便实现出栈操作
    node *next;
    int key;
    node(int x):pre(NULL),next(NULL),key(x){}
};
//链式栈
struct list
{
    node *Head;//栈的起始结点
    node *Top;//栈顶指针
    list(){Head = new node(0);Top = Head;}
};
//打印栈中的元素
void Print(list *L)
{
    node *p = L->Head->next;
    while(p)
    {
        cout<<p->key<<' ';
        p = p->next;
    }
    cout<<endl;
}
//入栈
void Push(list *L, int x)
{
    //构造一个新的结点
    node *A = new node(x);
    //链入到栈顶位置，修改指针
    L->Top->next = A;
    A->pre = L->Top;
    L->Top = A;
}
//出栈
int Pop(list *L)
{
    if(L->Head == L->Top)
    {
        cout<<"error:underflow"<<endl;
        return -1;
    }
    //取出栈顶元素
    int ret = L->Top->key;
    //修改指针
    node *A = L->Top;
    L->Top = A->pre;
    L->Top->next = NULL;
    delete A;
    return ret;
}
