class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1, mid;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            if(target == nums[mid]) return true;
            if(nums[left] == nums[mid] && nums[right] == nums[mid])
            {
                left++;
                right--;
            }
            else if(nums[left] <= nums[mid])
            {
                if(target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if(target > nums[mid] && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};