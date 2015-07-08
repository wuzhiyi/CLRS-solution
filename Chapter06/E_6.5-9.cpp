/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 6.5-9
 * 名称:  K-WAY-MERGING
 * 作者:  windmissing
 * 语言:  c++
 * 内容摘要: 使用最小堆完成K路归并排序
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150708       V1.0          wuzhiyi      创建
 **************************************************************/

/* 产品代码 */
#include <iostream>
#include <vector>
using namespace std;

#include <stdlib.h>

#include "Exercise6_5_8.h"
#include "Heap.h"

#define K 10
#define DATA_COUNT 100

ostream& operator<<(ostream & s, const node & n)
{
    s << n.value;
    return s;
}

//5个链表，每个链表的头结点放入Head中
int mergeResult[DATA_COUNT+1] = {0};
CMaxHeap<node> H(K, node::getMaxNode());

vector<ARRAY> buildTestData();
void showTestData(vector<ARRAY> inputParam);
void insertListHeadToHeap(vector<ARRAY> &inputParam, int listIndex);
void showResult();
void recordMergeResult(int data);
ARRAY solve_6_5_8(vector<ARRAY> inputParam);

int K_Merge_6_5_8()
{
    vector<ARRAY> inputParam = buildTestData();
    showTestData(inputParam);
    
    ARRAY result = solve_6_5_8(inputParam);
    
    showResult();
    return 0;
}

ARRAY solve_6_5_8(vector<ARRAY> inputParam)
{
    ARRAY ret;
    while(H.isEmpty() == false)
        H.extract();
    
    for(int i = 0; i < inputParam.size(); i++)
        insertListHeadToHeap(inputParam, i);
    while(H.isEmpty() == false)
    {
        node top = H.extract();
        ret.push_back(top);
        insertListHeadToHeap(inputParam, top.list);
    }
    return ret;
}

vector<ARRAY> buildTestData()
{
    int value, list;
    //构造需要合并的数据
    vector<ARRAY > ret(K);
    for(value = DATA_COUNT; value >0; value--)
    {
        list = rand() % K;
        node newNode;// = {list, value};
        newNode.list = list;
        newNode.value = value;
        ret[list].push_back(newNode);
    }
    return ret;
}

void showTestData(vector<ARRAY> inputParam)
{
    cout<<"显示待排序数据"<<endl;
    for(int i = 0; i < inputParam.size(); i++)
    {
        ARRAY array = inputParam[i];
        for(int j = 0; j < array.size(); j++)
            cout<<array[j].value<<' ';
        cout<<endl;
    }
}

void insertListHeadToHeap(vector<ARRAY> &inputParam, int  listIndex)
{
    ARRAY &array = inputParam[listIndex];
    if(array.size() != 0)
    {
        H.insert(array[0]);
        array.erase(array.begin());
    }
}

void showResult()
{
    //输出合并结果
    cout<<"输出合并结果"<<endl;
    for(int i = 1; i <= mergeResult[0];i++)
        cout<<mergeResult[i]<<' ';
    cout<<endl;
}

void recordMergeResult(int data)
{
    mergeResult[++mergeResult[0]] = data;
}

/* 测试代码 */
#include <iostream>
using namespace std;

#include "Exercise6_5_8.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"
// Tests factorial of negative numbers.
//
using ::testing::_;
using ::testing::SetArgPointee;
using ::testing::DoAll;
using ::testing::Return;
using ::testing::Pointee;

ARRAY setArray(int *initArray, int len, int list)
{
    ARRAY ret;
    for(int i = 0; i < len; i++)
    {
        node newNode;
        newNode.value = initArray[i];
        newNode.list = list;
        ret.push_back(newNode);
    }
    return ret;
}

bool compare(ARRAY A, ARRAY B)
{
    if(A.size() != B.size())
        return false;
    for(int i = 0; i < A.size(); i++)
        if(A[i].value != B[i].value)
            return false;
    return true;
}

TEST(only_one_array, only_one_data_in_array)
{
    int initArray[1] = {5};
    ARRAY array = setArray(initArray, 1, 0);
    vector<ARRAY> inputParam;
    inputParam.push_back(array);
    
    ARRAY result = solve_6_5_8(inputParam);
    EXPECT_TRUE(compare(array, result));
}

void printArray(ARRAY array)
{
    for(int i = 0; i < array.size(); i++)
        cout<<array[i].value<<' ';
    cout<<endl;
}

TEST(two_array, only_one_data_in_array)
{
    int initArray1[1] = {5};
    ARRAY array1 = setArray(initArray1, 1, 0);
    int initArray2[1] = {4};
    ARRAY array2 = setArray(initArray2, 1, 1);
    vector<ARRAY> inputParam;
    inputParam.push_back(array1);
    inputParam.push_back(array2);
    
    ARRAY result = solve_6_5_8(inputParam);
    
    int expectArray[2] = {5, 4};
    ARRAY expect = setArray(expectArray, 2, 0);
    EXPECT_TRUE(compare(expect, result));
}

TEST(two_array, negitave_data_in_array)
{
    int initArray1[5] = {13, 10, 7, -1, -4};
    ARRAY array1 = setArray(initArray1, 5, 0);
    int initArray2[10] = {15, 14, 12, 11, 9, 8, 6, 0, -2, -3};
    ARRAY array2 = setArray(initArray2, 10, 1);
    vector<ARRAY> inputParam;
    inputParam.push_back(array1);
    inputParam.push_back(array2);
    
    ARRAY result = solve_6_5_8(inputParam);
    
    int expectArray[15] = {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 0, -1, -2, -3, -4};
    ARRAY expect = setArray(expectArray, 15, 0);
    EXPECT_TRUE(compare(expect, result));
}

TEST(three_array, different_data_count_in_array)
{
    int initArray1[6] = {10, 9, 8, 4, 3, 2};
    ARRAY array1 = setArray(initArray1, 6, 0);
    int initArray2[2] = {7, 1};
    ARRAY array2 = setArray(initArray2, 2, 1);
    int initArray3[4] = {6, 5, 0, -1};
    ARRAY array3 = setArray(initArray3, 4, 2);
    vector<ARRAY> inputParam;
    inputParam.push_back(array1);
    inputParam.push_back(array2);
    inputParam.push_back(array3);
    
    ARRAY result = solve_6_5_8(inputParam);
    
    int expectArray[15] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1};
    ARRAY expect = setArray(expectArray, 12, 0);
    EXPECT_TRUE(compare(expect, result));
}
