/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:  Problem 13-1
 * 名称:  持久动态集合
 * 作者:  windmissing
 * 语言:  C++
 * 内容摘要: 持久动态集合
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150709       V1.0          wuzhiyi      创建
**************************************************************/
//持久动态集合上的树的插入操作
tree* Persistent_Tree_Insert(tree *T, int k)
{
    //从根结点开始
    node *p = T->root, *f, *f2;   // f为旧结点，f2为新结点
    //首先根结点是一定要改变的
    T->root = new node(p);
    //改变p结点的孩子，不需要改变的那个，还是指向原来的孩子
    while(p->key != k)
    {
        if(k < p->key)
        {
            //为要改的那个孩子建立一个和它一样的新结点
            f = p->left;
            //若孩子为空，把新结点加入进去
            if(!f)
                f2 = new node(k);
            else
                f2 = new node(f);
            //p指向新孩子
            p->left = f2;
        }
        else
        {
            f = p->right;
            if(!f)
                f2 = new node(k);
            else
                f2 = new node(f);
            p->right = f2;
        }
        //以新结点为父结点，做同样的更新操作
        p = f2;
    }
    //返回树
    return T;
}
