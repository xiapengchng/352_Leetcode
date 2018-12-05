class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int i,k,n=nums.size()-1;
        vector<int> F(nums.size(),0);
        if(nums.size()==1)
        {
            return nums[0];
        }
        F[n]=nums[n];
        F[n-1]=max(nums[n],nums[n-1]);
        for(i=n-2;i>=0;i--)
            F[i]=max(F[i+1],nums[i]+F[i+2]);
        return F[0];
    }
};
