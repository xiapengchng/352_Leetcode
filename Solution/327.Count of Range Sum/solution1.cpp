class Solution {
public:
    int Lo,Up;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        Lo=lower;
        Up=upper;
        int i;
        if(nums.size()==0)
            return 0;
        vector<long> sums;
        sums.push_back(nums[0]);
        for(i=1;i<nums.size();i++){
            sums.push_back(sums.back()+nums[i]);
        }
        return f(sums,0,nums.size()-1);
    }
    int f(vector<long>& nums,int lo,int hi)
    {
        if(lo>=hi){
            if(Lo<=nums[lo]&&nums[lo]<=Up)
                return 1;
            else
                return 0;
        }
        int i,j,mi,k,cnt1,cnt2;
        mi=(lo+hi)/2;
        vector<long> temp(hi-lo+1,0);
        cnt1=f(nums,lo,mi);
        cnt2=f(nums,mi+1,hi);
        
        i=lo,j=mi+1;
        int c1=0,c2=0;
        while(i<=mi&&j<=hi){
            if(nums[j]-nums[i]<Lo){
                c1=c1+(mi-i+1);
                j++;
            }
            else
                i++;
        }
        i=lo,k=mi+1;
        while(i<=mi&&k<=hi){
            if(nums[k]-nums[i]<=Up){
                c2=c2+(mi-i+1);
                k++;
            }
            else
                i++;
        }
        
        //mergesort
        i=lo,j=mi+1,k=0;
        while(i<=mi&&j<=hi){
            if(nums[i]<nums[j]){
                temp[k++]=nums[i++];
            }
            else
                temp[k++]=nums[j++];
        }
        while(i<=mi){
            temp[k++]=nums[i++];
        }
        while(j<=hi){
            temp[k++]=nums[j++];
        }
        for(i=lo;i<=hi;i++){
            nums[i]=temp[i-lo];
        }
        return cnt1+cnt2+c2-c1;
        
    }
};
