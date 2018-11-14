class Solution {
public:
    int climbStairs(int n) {
        if(n == 1 && n == 2) return n;
        vector<int> res(n+1);
        res[1] = 1;
        res[2] = 2;
        for(int i = 3; i <= n; i++)
            res[i] = res[i-1] + res[i-2];
        return res[n];
        
    }
};
