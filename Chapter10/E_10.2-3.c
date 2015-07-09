/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 10.2-3
 * 名称:  Singly linked list-queue
 * 作者:  windmissing
 * 语言:  c
 * 内容摘要: 单链表实现队列 
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
//结点
struct node
{
    node *next;
    int key;
    node(int x):next(NULL),key(x){}
};
//链式队列
struct list
{
    node *Head;//头指针
    node *Tail;//尾指针
    list(){Head = new node(0);Tail = Head;}
};
//打印
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
//入队列
void Enqueue(list *L, int x)
{
    //构造一个新的结点
    node *A = new node(x);
    //链入尾部，修改指针
    L->Tail->next = A;
    L->Tail = A;
}
//出队列
int Dequeue(list *L)
{
    if(L->Head == L->Tail)
    {
        cout<<"error:underflow"<<endl;
        return -1;
    }
    //取出队头结点，修改指针
    node *A = L->Head->next;
    int ret = A->key;
    L->Head->next = A->next;
    if(A == L->Tail)
        L->Tail = L->Head;
    delete A;
    return ret;
}
