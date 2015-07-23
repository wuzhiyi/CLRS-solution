/**************************************************************
 * Copyright (c) Wuzhiyi
 * Introduction to Algorithms
 *
 * 题目:
 * 名称:  暴力破解additive cipher
 * 作者:  wuzhiyi
 * 语言:  c
 * 内容摘要: 输出所有 key 情况
 *
 * 修改记录:
 * 修改日期       版本号       修改人       修改内容
 * ------------------------------------------------------------
 * 20150718      V1.0       wuzhiyi      创建
 **************************************************************/
#include <stdio.h>
#include <ctype.h>


int main() {
    //输入 ciphertext
    char s[]="OTWEWNGWCBPQABIZVQAPMLJGZWTTQVOBQUMAPMIDGZCABEQVBMZLZIXMLAXZQVOQVLMMXAVWEIVLLIZSNZWABJQZLWNLMTQOPBVIUMLGWCBPAEQNBTGTMNBBPMVMABITIAKWCTLVBBQUMQBEPQTMQBEIAQVUGBZCAB";
    int A[162], i=0, j;
    
    //转化为小写
    printf("tolower:\n");
    for (i=0; i<162; i++) {
        s[i]=tolower(s[i]);
        printf("%c", s[i]);
        }
    
    //将字母转为 ascii 码
    printf("\ntoascii\n");
    //key 从1到26，所有情况
    for (j=1; j<26; j++) {
        printf("\nkey = %d:\n", j);
        for (i=0; i<162; i++) {
            A[i]=toascii(s[i])-j;
            if (A[i]<97) {  //若超出小写字母数字范围，取模，使数值合理
                A[i]=A[i]+26;
            }
            printf("%c", A[i]); //每个小循环输出给定 key 值下的转换结果，即 plaintext
        }
        printf("\n");
    }
}
