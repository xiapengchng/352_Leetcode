class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        
        int cnt=1,ref=nums[0],i,j;
        auto iter=nums.begin();
        iter++;
        for(;iter!=nums.end();){
            if(*iter==ref){
                nums.erase(iter);
            }
            else{
                ref=*iter;
                cnt++;
                iter++;
            }
        }
        return cnt;
    }
};