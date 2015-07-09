/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Exercise 14.3-1~5
 * 名称:  习题
 * 作者:
 * 语言:
 * 内容摘要:
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0       wuzhiyi      创建
 **************************************************************/
/* EXERCISE 14.3-1
 * LEFT-ROTATE(T, x) 
 * 伪代码 */
y = x.right         //令y为x的右孩子
x.right = y.left    //x的右孩子（指针）指向y的左孩子（有可能为T.nil）
if y.left != T.nil  //如果y的左孩子不为T.nil
then y.left.p = x   //y的左孩子父结点（指针）指向x
y.p = x.p           //y的父结点（指针）指向x的父结点（指针）
if x.p = T.nil              //如果x是根结点
    then T.root = y         //T.root指向y
    else if x = x.p.left    //如果x是左孩子
        then x.p.left = y   //y成为左孩子
        else x.p.right = y  //y成为右孩子
y.left = x      //y的左孩子（指针）指向x
x.p = y         //x的父结点（指针）指向y
y.max = x.max   //y.max取整棵x结点树的最大值（x.max>=y.max）
x.max = max(x.int.high, x.left.max, x.right.max)    //x.max重新取值


/* EXERCISE 14.3-3
 * 给定区间i，返回一个与i重叠且具有最小低端点的区间；
 * 或者当这样的区间不存在时返回T.nil */
node* Intervel_Tree::Search_Min(node *root, interval i)
{
    node *x = root, *y; //初始化，x指向根结点
    /* 先从左子树开始搜索 */
    if (x->left && x->left->max >= i.low)
    {
        y = Search_Min(x->left, i);
        if (y != nil)
            return y;
    }
    /* 如果x与i重叠，就不搜索左子树 */
    if (Overlap(x->inte, i))
        return x;
    /* 在右子树上找 */
    if (x->right)
        return Search_Min(x->right, i);
    return nil;
}

/* EXERCISE 14.3-4
 * 给定区间树T和区间i，在O(min(n,klgn))时间内列出T中所有与i重叠的区间，
 * 其中k为输出的区间数 */
void Interval_Tree::Search_All(node *root, interval i)
{
    node *x = root, *y;
    //如果当前结点与i重叠
    if (Overlap(x->inte, i))
        cout<<x->inte.low<<' '<<x->inte.high<<endl;
    //先从左子树上找
    if (x->left && x->left->max >= i.low)
        Search_All(x->left, i);
    //从右子树上找
    if (x->right && x->key <= i.high)
        Search_All(x->right, i);
}

/* EXERCISE 14.3-5
 * 给定区间树T和区间i，返回一个指向T中结点x的指针，
 * 使得 x.int.low=i.low 且 x.int.high=i.high;
 * 或，如果T不包含这样的区间时返回T.nil 
 * INTERVAL-SEARCH-EXACTLy(T, i) */
node* Interval_Tree::Search_Exactly(interval i)
{
    //从根节点开始
    node *x = root;
    //不是叶子且不重叠
    while (x != nil)
    {
        if (x->inte.low == i.low && x->inte.high == i.high)
            return x;
        //在左子树中
        if (x->left != nil && x->key >= i.low)
            x = x->left;
        //在右子树中
        else
            x = x->right;
    }
    return nil;
}


