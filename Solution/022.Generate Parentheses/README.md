输入：n
输出：所有的n对括号的组合方案
示例：
输入：n=2
输出：["()()","(())"]
输入：n=3
输出：["()()()","()(())","(())()","(()())","((()))"]

技巧：
从函数递归调用的角度设计括号的组合，有2个变量open和close分别记录'('和')'