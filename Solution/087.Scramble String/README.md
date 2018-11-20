Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.

Example 1:

Input: s1 = "great", s2 = "rgeat"
Output: true
Example 2:

Input: s1 = "abcde", s2 = "caebd"
Output: false

solution1.cpp
一个近乎暴力枚举的递归方法[笑哭],但是也通过了，希望你们可以提出更高效的方法。
若s1字符串的[s1_lo,s1_hi]范围和s2字符串的[s2_lo,s2_hi]范围可以匹配，则F[s1_lo][s1_hi][s2_lo][s2_hi]=true；否则F[s1_lo][s1_hi][s2_lo][s2_hi]=false，递归关系如下：
        int i;
        bool tag1,tag2;
        tag1=false;tag2=false;
        for(i=0;i<s1_hi-s1_lo;i++)
        {
            tag1=Func(s1_lo,s1_lo+i,s2_lo,s2_lo+i)&&Func(s1_lo+i+1,s1_hi,s2_lo+i+1,s2_hi);
            if(tag1)
                break;
            tag2=Func(s1_lo,s1_lo+i,s2_hi-i,s2_hi)&&Func(s1_lo+i+1,s1_hi,s2_lo,s2_hi-i-1);
            if(tag2)
                break;
        }
        F[s1_lo][s1_hi][s2_lo][s2_hi]=tag1||tag2;