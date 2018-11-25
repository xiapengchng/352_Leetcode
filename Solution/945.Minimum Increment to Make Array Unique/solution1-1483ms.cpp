class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        

        if(A.size()<=1)
            return 0;
        vector<int> res;
        int F[A.size()]={0};
        F[0]=0;
        if(A[0]!=A[1]){
            F[1]=0;
            res.push_back(A[0]);
            res.push_back(A[1]);
            sort(res.begin(),res.end());
        }  
        else{
            F[1]=1;
            res.push_back(A[0]);
            res.push_back(A[1]+1);

        }
        int i,j,start,end,num;
        for(i=2;i<A.size();i++){
        start=res.front();
        end=res.back();
        if(A[i]<start){
            res.insert(res.begin(),A[i]);
            F[i]=F[i-1];
        }
        else if(A[i]>end){
            res.insert(res.end(),A[i]);
            F[i]=F[i-1];
        }
        else{
            auto iter=lower_bound(res.begin(),res.end(),A[i]);//O(log(m))
            if(iter!=res.end()&&*iter==A[i]){//找到了
                // cout<<"find"<<endl;
                
                num=end-start+1;
                if(res.size()==end-start+1){//满了
                    res.insert(res.end(),end+1);
                    F[i]=F[i-1]+end+1-A[i];
                }
                else{//没满
                    for(j=0;iter!=res.end();iter++,j++){//O(?)
                        if(*iter!=A[i]+j)
                            break;
                    }
                    res.insert(iter,A[i]+j);
                    F[i]=F[i-1]+j;
                    
                }
            }
            else{//没找到
                // cout<<"no find"<<endl;
                res.insert(iter,A[i]);
                F[i]=F[i-1];
            }
        }
        // for(auto j:res)
        //     cout<<j<<" ";
        // cout<<endl;
        }
        return F[A.size()-1];
    }
};