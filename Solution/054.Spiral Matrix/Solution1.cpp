class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        int nr = matrix.size();
        if(nr == 0) return res;
        int nc = matrix[0].size();
        if(nc == 0) return res;
        vector<int> nsteps{nc, nr-1};
        int idir = 0;
        nr = 0;
        nc = -1;
        while(nsteps[idir%2])
        {
            for(int i = 0; i < nsteps[idir%2]; i++)
            {
                nr += dir[idir][0];
                nc += dir[idir][1];
                res.push_back(matrix[nr][nc]);
            }
            nsteps[idir%2]--;
            idir = (idir+1) % 4;
        }
        return res;
    }
};
