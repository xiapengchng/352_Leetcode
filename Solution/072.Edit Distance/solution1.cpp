class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        if(n2==0)
            return n1;
        if(n1==0)
            return n2;
        int i,j,ref;
        vector<vector<int>> F(n1,vector<int>(n2,0));
        
        if(word1[n1-1]==word2[n2-1])
            F[n1-1][n2-1]=0;
        else
            F[n1-1][n2-1]=1;
        
        for(i=n1-2;i>=0;i--){
            if(word1[i]==word2[n2-1])
                F[i][n2-1]=n1-1-i;    
            else
                F[i][n2-1]=1+F[i+1][n2-1];
        }
        for(j=n2-2;j>=0;j--){
            if(word1[n1-1]==word2[j])
                F[n1-1][j]=n2-1-j;    
            else
                F[n1-1][j]=1+F[n1-1][j+1];
        }
        for(i=n1-2;i>=0;i--){
            for(j=n2-2;j>=0;j--){
                if(word1[i]==word2[j])
                    F[i][j]=F[i+1][j+1];
                else{  
                    ref=1+F[i][j+1]; 
                    if(ref>1+F[i+1][j])
                        ref=1+F[i+1][j];
                    if(ref>1+F[i+1][j+1])
                        ref=1+F[i+1][j+1];
                    F[i][j]=ref;
                }
            }
        }
        return F[0][0];
    }
};