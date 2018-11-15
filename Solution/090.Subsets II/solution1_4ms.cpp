bool compare(vector<int> &a1,vector<int>&a2)
{
    if(a1.size()>a2.size())
        return true;
    if(a1.size()==a2.size())
    {
        for(int i=0;i<a2.size();i++)
        {
            if(a1[i]>a2[i])
                return true;
                
        }
    }
    return false;
}
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> sample;
        sort(nums.begin(),nums.end());
        result.push_back(sample);
        for(int i=0;i<nums.size();i++)
        {
            int sz=result.size();
            for(int j=0;j<sz;j++)
            {
                //cout<<i<<","<<j<<endl;
                vector<int> sam=result[j];
                sam.push_back(nums[i]);
                result.push_back(sam);
            }
        }
        sort(result.begin(),result.end(),compare);
        vector<vector<int>>::iterator it=unique(result.begin(),result.end());
        result.erase(it,result.end());
        return result;
        
    }
};
