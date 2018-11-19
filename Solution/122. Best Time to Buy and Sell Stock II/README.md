Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).

Example 1:

Input: [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
             Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Example 2:

Input: [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
             Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
             engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

DP方法，见solution1.cpp 
F[flags,n]表示收益，flags=0 or 1，A[n]表示股票每天的价格.F[1,n]表示前n天处于卖出状态的最大收益；F[0,n]表示前n天处于买入状态的最大收益
DP方程为：
F[0][n]=max(F[1][n-1]-A[n],F[0][n-1]);
F[1][n]=max(F[1][n-1],F[0][n]+A[n]);
返回值为F[1][N]
复杂度为O(2n)