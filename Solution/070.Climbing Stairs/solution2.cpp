class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        vector<long long> res(n+1,0);
        
        res[1]=1;
        res[2]=2;
        int i;
        for(i=3;i<=n;i++){
            res[i]=res[i-1]+res[i-2];
        }
        return res[n];
    }
};
