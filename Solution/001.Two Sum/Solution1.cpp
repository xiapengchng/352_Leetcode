class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> dict;
        for(int i=0;i<nums.size();i++)
        {
             dict[nums[i]]=i;
            int cha=target-nums[i];
            //cout<<i<<"res"<<cha<<"dict"<<dict[cha]<<endl;
            if(dict[cha]>0&&dict[cha]!=i)
            {
                vector<int> vec{i,dict[cha]};
                return vec;
            }
           
        }
    }
};
