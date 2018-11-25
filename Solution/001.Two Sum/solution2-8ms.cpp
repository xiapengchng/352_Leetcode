class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ori=nums;
        sort(nums.begin(),nums.end());
        int lo=0,hi=nums.size()-1;
        vector<int> res;
        while(lo<hi){
            if(nums[lo]+nums[hi]>target)
                hi--;
            else if(nums[lo]+nums[hi]<target)
                lo++;
            else
            {
                res.push_back(find(ori,nums[lo]));
                res.push_back(find(ori,nums[hi]));
                break;
            }
        }
        return res;
    }
    int find(vector<int>& ori,int target){
        int i;
        for(i=0;i<ori.size();i++){
            if(ori[i]==target){
                ori[i]=target+1;
                return i; 
            }
        }
        return 0;
    }
};