class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obs) {
        int m = obs.size();
        int n = obs[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        if(obs[0][0] == 1) return 0;
        res[0][0] = 1;
        for(int i = 1; i < n; i++)
        {
            if(obs[0][i] == 1)
                res[0][i] = 0;
            else
                res[0][i] = res[0][i-1];   
        }
        for(int i = 1; i < m; i++)
        {
            if(obs[i][0] == 1)
                res[i][0] = 0;
            else 
                res[i][0] = res[i-1][0];
        }
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
            {
                if(obs[i][j] == 1)
                    res[i][j] = 0;
                else
                    res[i][j] = res[i-1][j] + res[i][j-1];
            }
        return res[m-1][n-1];
        
    }
};