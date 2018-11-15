class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int u = 0, d = m - 1, l = 0, r = n -1, k = 0;
        vector<int> res(m*n);
        while(true)
        {
            for(int col = l; col <= r; col++)
                res[k++] = matrix[u][col];
            if(++u > d) break;
            for(int row = u; row <= d; row++)
                res[k++] = matrix[row][r];
            if(--r < l) break;
            for(int col = r; col >= l; col--)
                res[k++] = matrix[d][col];
            if(--d < u) break;
            for(int row = d; row >=u; row--)
                res[k++] = matrix[row][l];
            if(++l > r) break;
        }
        return res;
        
    }
};
