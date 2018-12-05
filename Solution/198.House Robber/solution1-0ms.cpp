class Solution {
public:
    int rob(vector<int>& nums) {
        //F[n]
        int i,n=nums.size()-1;
        if(nums.size()==0)
            return 0;
        vector<int> F(nums.size(),0);
        F[0]=nums[0];
        F[1]=max(nums[0],nums[1]);
        for(i=2;i<=n;i++){
            F[i]=max(F[i-1],nums[i]+F[i-2]);
            //cout<<i<<" "<<F[i]<<endl;
        }
        return F[n];
    }
};
