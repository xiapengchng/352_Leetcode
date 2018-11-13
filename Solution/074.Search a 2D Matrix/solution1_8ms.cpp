lass Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        if(rows==0)
            return 0;
        int cols=matrix[0].size();
        if(cols==0)
            return 0;
        int i=0,j=rows-1,mid=(rows-1)/2;
        int row_pos=0;
        if(matrix[i][0]>target||target>matrix[j][cols-1])
            return false;
        if(target>=matrix[j][0])
            row_pos=j;
        else
        {
            while(j-i>=2)
            {
                if(target<matrix[mid][0])
                {
                    j=mid;
                    mid=(i+j)/2;
                }
                else
                {
                    i=mid;
                    mid=(i+j)/2;
                }
            }
            row_pos=i;
        }
        //cout<<row_pos;
        i=0;
        j=cols-1;
        if(target>matrix[row_pos][j])
            return false;
        mid=(cols-1)/2;
        while(j-i>=2)
        {
            if(target>matrix[row_pos][mid])
            {
                i=mid;
                mid=(i+j)/2;
            }
            else
            {
                j=mid;
                mid=(i+j)/2;
            }
        }
        if(matrix[row_pos][i]==target||matrix[row_pos][j]==target)
            return true;
            

        return false;
        
    }
};



