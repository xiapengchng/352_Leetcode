class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        if(nums.size()==0)
            return vector<int>();
        cout<<nums.size()<<endl;
        vector<int> indice(nums.size(),0);
        vector<int> count(nums.size(),0);
        f(nums,indice,count,0,nums.size()-1);
        return count;
    }
    void f(vector<int>&nums,vector<int>& indice,vector<int>& count,int lo,int hi){
        if(lo>=hi){
            indice[lo]=lo;
            count[lo]=0;
            return;
        }
        int mi=(lo+hi)/2;
        int i,j,k,countvalue;
        //cout<<lo<<" "<<hi<<endl;
        f(nums,indice,count,lo,mi);
        f(nums,indice,count,mi+1,hi);
        //cout<<"ok"<<endl;
        i=lo,j=mi+1,k=0;
        countvalue=0;
        int* new_indice=new int[hi-lo+1];
        while(i<=mi&&j<=hi){
            if(nums[indice[i]]>nums[indice[j]]){
                countvalue++;
                new_indice[k]=indice[j];
                j++;
                k++;
            }
            else{
                count[indice[i]]=count[indice[i]]+countvalue;
                new_indice[k]=indice[i];
                i++;
                k++;
            }
        }
        while(j<=hi){
            new_indice[k]=indice[j];
            j++;
            k++;

        }
        while(i<=mi){
            count[indice[i]]=count[indice[i]]+countvalue;
            new_indice[k]=indice[i];
            i++;
            k++;
        }
        // indice=new_indice;
        for(i=lo;i<=hi;i++)
            indice[i]=new_indice[i-lo];
        delete[] new_indice;
        // new_indice.clear();
        // new_indice;
        // delete new_indice;
        return;
    }
};
