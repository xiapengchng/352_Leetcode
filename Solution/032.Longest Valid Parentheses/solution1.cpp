class Solution {
public:
    int longestValidParentheses(string s) {
         
        if(s.size()==0)
            return 0;
        string A=s;
        int n,cnt,i,F[A.size()]={0};
        F[0]=0;
        for(n=1;n<A.size();n++){

            if(A[n]=='('){
                F[n]=0;
            }
            else{//A[n]==')'
                cnt=0;
                if(A[n-1]=='('){
                    cnt=2;
                    i=n-2;
                    if(i>=0&&F[i]!=0)
                        cnt=cnt+F[i];
                }
                else{//A[n-1]==')'
                    if(F[n-1]!=0&&n-F[n-1]-1>=0&&A[n-F[n-1]-1]=='('){
                        cnt=F[n-1]+2;
                        i=n-F[n-1]-1-1;
                        if(i>=0&&F[i]!=0)
                            cnt=cnt+F[i];
                    }
                }
                F[n]=cnt;
            }
        }
        int ref_i=0,ref=F[0];
        for(i=1;i<A.size();i++){
            //cout<<F[i]<<" ";
            if(F[i]>ref){
                ref_i=i;
                ref=F[i];
            }
        }    
        
        return ref;
    }
};