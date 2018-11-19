class Solution {
public:
    int maxProfit(vector<int>& A) {
        int n=A.size();
        if(n==0)
            return 0;
        vector<vector<int>> F(2,vector<int>(n,0));
        F[0][0]=-A[0];
        F[1][0]=0;
        int i;
        for(i=1;i<n;i++){
            F[0][i]=max(F[1][i-1]-A[i],F[0][i-1]);
            F[1][i]=max(F[1][i-1],F[0][i]+A[i]);
        }
        return F[1][n-1];
    }
    
};