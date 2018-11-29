class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //method1:
        //return lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        
        //method2:
        int* a=new int[nums.size()];
        for(int i=0;i<nums.size();i++)
            a[i]=nums[i];
        int pos=lower_bound(a,a+nums.size(),target)-a;
        delete[] a;
        return pos;
        
    }
};