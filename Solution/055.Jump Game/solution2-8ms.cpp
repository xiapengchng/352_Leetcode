class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,n,j,ref,ref_i;
        if(nums.size()==0)
            return true;
        i=0;
        while(i<nums.size()&&nums[i]){
            n=nums[i];
            ref=-1;
            ref_i=i;
            for(j=1;j<=n;j++){
                if(i+j>=nums.size()-1){
                    ref_i=j+nums.size();
                    break;
                }
                if(j+nums[i+j]>ref){
                    ref=j+nums[i+j];
                    ref_i=i+j;
                }
            }
            i=ref_i;
        }
        if(i<nums.size()-1)
            return false;
        else
            return true;
        
    }
};