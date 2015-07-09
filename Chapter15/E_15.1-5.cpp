/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 15.1-5
 * 名称:  斐波那契数列
 * 作者:  YUWEI1989
 * 语言:  C++
 * 内容摘要: 动态规划算法计算斐波那契数
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709      V1.0       wuzhiyi      创建
**************************************************************/
/* 备忘方法解决斐波那契问题 */
int f(int n, int *r)
{
    if (n <= 0) {
        return 0;
    }
    if (r[n] >= 0) {
        return r[n];
    }
    
    r[n] = f(n-1, r) + f(n-2, r);
    
    return r[n];
}

/* 备忘方法 */
int Fabonacci_2(int n)
{
    int *r = (int *)malloc((n+1)*sizeof(int));
    int i = 0;
    for (i=0; i<=n; i++) {
        r[i] = -1;
    }
    r[0] = 0;
    r[1] = 1;
    return f(n, r);
}

/* 自底向上方法 */
int Fabonacci_3(int n)
{
    int i = 0;
    int *r = (int *)malloc((n+1)*sizeof(int));
    int result = 0;
    r[0] = 0;
    r[1] = 1;
    
    if (n <= 0) {
        return 0;
    }
    
    if (n==1) {
        return 1;
    }
    
    for (i=2; i<=n; i++) {
        result = r[i-2] + r[i-1];
        r[i] = result;
    }
    
    return result;
}
