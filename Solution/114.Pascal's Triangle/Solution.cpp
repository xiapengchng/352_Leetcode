class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows == 0)
            return {};
        vector<vector<int>> res;
        for(int i = 0; i < numRows; i++)
        {
            vector<int> p(i+1);
            p[0] = 1;
            p[i] = 1;
            for(int j = 1; j < i; j++)
            {
                p[j] = res[i-1][j-1] + res[i-1][j];
            }
            res.push_back(p);
        }
        return res;
    }
};
