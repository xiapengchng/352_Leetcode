class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        if(tri.size()==0)
            return 0;
        vector<int> top(tri.back().size(),0);
        vector<int> bott(tri.back().size(),0);
        int i,j,k=1,n;
        n=tri.back().size()-1;
        for(i=0;i<=n;i++)
            bott[i]=tri[n][i];
        n--;
        while(n>=0){
            //bott->top
            for(i=0;i<=n;i++){
                top[i]=min(bott[i],bott[i+1])+tri[n][i];
            }
            n--;
            bott=top;
        }
        return bott[0];
        
    }
};
