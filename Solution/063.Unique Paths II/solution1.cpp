class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int nrows=obstacleGrid.size(),ncols;
        if(nrows!=0){
            ncols=obstacleGrid[0].size();
            if(ncols==0)
                return 0;
        }
        else
            return 0;
        
        for(auto i:obstacleGrid)
            for(auto j:i)
                cout<<j<<" "; 
        cout<<nrows<<" "<<ncols<<endl;
        
        int i,j;
        vector<vector<int>> res=obstacleGrid;
        if(obstacleGrid[0][0]==1)
            return 0;
        res[0][0]=1;
        for(i=1;i<nrows;i++){
            if(obstacleGrid[i][0]==1)
                res[i][0]=0;
            else
                res[i][0]=res[i-1][0];
        }
        for(j=1;j<ncols;j++){
            if(obstacleGrid[0][j]==1)
                res[0][j]=0;
            else
                res[0][j]=res[0][j-1];
        }
        for(i=1;i<nrows;i++){
            for(j=1;j<ncols;j++){
                if(obstacleGrid[i][j]==1)
                    res[i][j]=0;
                else 
                    res[i][j]=res[i-1][j]+res[i][j-1];
            }
        }
        
        return res[nrows-1][ncols-1];
    }
};