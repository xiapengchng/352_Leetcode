class Solution {
public:
    int jump(vector<int>& nums) {
        int i,j,cnt,ref_i,ref;
        int n=nums.size();
        if(n==0)
            return 0;
        if(n==1)
            return 0;
        cnt=0;
        i=0;
        while(i<n-1&&nums[i]){
            ref_i=i;
            ref=-1;
            for(j=1;j<=nums[i];j++){
                if(j+i>=n-1){
                    ref_i=i+j;
                    break;
                }
                if(j+nums[i+j]>ref){
                    ref=j+nums[i+j];
                    ref_i=i+j;
                }
                
            }
            i=ref_i;
            cnt++;
        }
        if(i<n-1){
            return n-1;
        }
        else{
            return cnt;
        }
    }
};