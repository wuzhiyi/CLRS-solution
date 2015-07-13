/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 16.1-2
 * 名称:  最晚开始的活动
 * 作者:  windmissing
 * 语言:  cpp
 * 内容摘要: 选择最晚开始的活动，前提仍然是与之前的所有活动均兼容。
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709      V1.0       wuzhiyi      创建
 **************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

#define N 11
//一个活动用一个结点表示
struct node
{
    int id;
    int start;
    int finish;
}A[N+1];
bool cmp(node a, node b)
{
    return a.start < b.start;
}
//16.1-2
void Greedy_Activity_Selector2()
{
    //先对每个活动按照它们的开始时间从小到大排序
    sort(A, A+N+1, cmp);
    int n = N, i = -1, m;
    for(m = n; m >= 1; m--)
    {
        //找到最后一个“结束时间在第i个活动开始之前”的活动
        if(i == -1 || A[m].finish <= A[i].start)
        {
            //将这个活动作为执行活动
            cout<<A[m].id<<' ';
            //递归第m个活动执行开始之前的贪心策略
            i = m;
        }
    }
    cout<<endl;
}
/*
 0 0 //虚构活动a0
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
    for(i = 0; i <= N; i++)
    {
        A[i].id = i;
        cin>>A[i].start>>A[i].finish;
    }
    Greedy_Activity_Selector2();
    return 0;
}
