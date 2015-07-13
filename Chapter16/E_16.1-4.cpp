/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 16.1-4
 * 名称:  Interval-graph Color Problem
 * 作者:  windmissing:blog.csdn.net/mishifangxiangdefeng
 * 语言:  cpp
 * 内容摘要: 区间图着色问题
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709      V1.0       wuzhiyi      创建
 **************************************************************/
//Heap.h
#include <iostream>
#include <stdio.h>
using namespace std;

#define PARENT(i) (i)>>1
#define LEFT(i) (i)<<1
#define RIGHT(i) ((i)<<1)+1

int length = 0;//数组中元素的个数
int heap_size = 0;//属于堆的元素个数，看到HeapSort就会明白

/*************************以下是堆处理函数****************************************/
//使以i结点为根结点的子树成为堆，调用条件是确定i的左右子树已经是堆，时间是O(lgn)
//递归方法
void Max_Heapify(int *A, int i)
{
    int l = LEFT(i), r = RIGHT(i), largest;
    //选择i、i的左、i的右三个结点中值最大的结点
    if(l <= heap_size && A[l] > A[i])
        largest = l;
    else largest = i;
    if(r <= heap_size && A[r] > A[largest])
        largest = r;
    //如果根最大，已经满足堆的条件，函数停止
    //否则
    if(largest != i)
    {
        //根与值最大的结点交互
        swap(A[i], A[largest]);
        //交换可能破坏子树的堆，重新调整子树
        Max_Heapify(A, largest);
    }
}
/**********************以下是优先队列处理函数****************************************/
//将元素i的关键字增加到key，要求key>=A[i]
void Heap_Increase_Key(int *A, int i, int key)
{
    if(key < A[i])
    {
        cout<<"new key is smaller than current key"<<endl;
        exit(0);
    }
    A[i] = key;
    //跟父比较，若A[PARENT(i)]<A[i]，则交换
    //若运行到某个结点时A[PARENT(i)]>A[i]，就跳出循环
    while(A[PARENT(i)] > 0 && A[PARENT(i)] < A[i])
    {
        swap(A[PARENT(i)], A[i]);
        i = PARENT(i);
    }
}
//把key插入到集合A中
void Max_Heap_Insert(int *A, int key)
{
    if(heap_size == 99)
    {
        cout<<"heap is full"<<endl;
        exit(0);
    }
    heap_size++;length++;
    A[heap_size] = -0x7fffffff;
    Heap_Increase_Key(A, heap_size, key);
}
//返回A中最大关键字，时间O(1)
int Heap_Maximum(int *A)
{
    return A[1];
}
//去掉并返回A中最大关键字，时间O(lgn)
int Heap_Extract_Max(int *A)
{
    if(heap_size < 1)
    {
        cout<<"heap underflow"<<endl;
        exit(0);
    }
    //取出最大值
    int max = A[1];
    //将最后一个元素补到最大值的位置
    A[1] = A[heap_size];
    heap_size--;
    //重新调整根结点
    Max_Heapify(A, 1);
    //返回最大值
    return max;
}
//删除堆中第i个元素
void Heap_Delete(int *A, int i)
{
    if(i > heap_size)
    {
        cout<<"there's no node i"<<endl;
        exit(0);
    }
    //把最后一个元素补到第i个元素的位置
    int key = A[heap_size];
    heap_size--;
    //如果新值比原A[i]大，则向上调整
    if(key > A[i])
        Heap_Increase_Key(A, i, key);
    else//否则，向下调整
    {
        A[i] = key;
        Max_Heapify(A, i);
    }
}

/***************************** main.cpp ****************************/
// main.cpp
#include <iostream>
#include "Heap.h"
using namespace std;

#define N 11
//用于存储每个活动的信息
struct node
{
    int id;//记录它是第几个活动
    int start;//开始时间
    int finish;//结束时间
}A[N+1];
//用于排序
bool cmp(node a, node b)
{
    return a.finish < b.finish;
}
//最大堆
int H[N+1];
//O(lgn)贪心算法
void Greedy()
{
    //对所有活动的结束时间从小到大排序
    sort(A+1, A+N+1, cmp);
    int i, ret = 0;
    //从最后一个活动开始，向第一个活动，依次针对每个活动做以下处理
    for(i = N; i >= 1; i--)
    {
        //1）获取堆顶元素的信息（4）更新堆（5）选择下一个活动，直到所有活动都处理过
        int temp = Heap_Maximum(H);
        //（2）如果堆顶的活动开始时间早于当前活动的结束时间，则：
        if(temp < A[i].finish)
        {
            //申请一个新的教室
            ret++;
            //把活动的开始时间填入其中，再把教室作为一个结点存入堆中
            Max_Heap_Insert(H, A[i].start);
        }
        //（3）如果堆顶的活动开始时间晚于当前活动的结束时间，则：
        else
        {
            //就把当前活动填入堆顶元素中
            Heap_Extract_Max(H);
            Max_Heap_Insert(H, A[i].start);
        }
        //选择下一个活动，直到所有活动都处理过
    }
    cout<<ret<<endl;
}
/*
 1 4
 3 5
 0 6
 5 7
 3 8
 5 9
 6 10
 8 11
 8 12
 2 13
 12 14
 */
int main()
{
    int i;
    //输入测试数据
    for(i = 1; i <= N; i++)
    {
        A[i].id = i;
        cin>>A[i].start>>A[i].finish;
    }
    //贪心算法
    Greedy();
    return 0;
}
