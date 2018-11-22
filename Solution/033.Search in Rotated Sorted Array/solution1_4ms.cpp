class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find pivot
        if(nums.size()==0)
            return -1;
        if(nums.size()==1)
            return nums[0]==target?0:-1;
        if(nums.size()==2)
        {
            if(nums[0]==target)
                return 0;
            if(nums[1]==target)
                return 1;
            return -1;
        }
        int left=0,right=nums.size()-1,pivot=0;
        int mid=right/2;
        if(nums[left]<nums[right])
        {
            if(nums[left]==target)
                return left;
            if(nums[right]==target)
                return right;
            while(right-left>1)
            {
                if(nums[mid]==target)
                {
                    return mid;
                }
                if(target<nums[mid])
                {
                    right=mid;
                    mid=(left+right)/2;
                }
                if(target>nums[mid])
                {
                    left=mid;
                     mid=(left+right)/2;
                }
            }
            
            
            
        }
        else{
        if(nums[left]>nums[left+1])
            pivot=left;
        else if(nums[right]<nums[right-1])
            pivot=right-1;
        else
        {
            while(left<right)
            {
                if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
                {
                    pivot=mid;
                    break;
                }
                else if(nums[mid]>nums[left]&&nums[mid]>nums[right])
                {
                    left=mid;
                    mid=(right+left)/2;
                }
                else if(nums[mid]<nums[left]&&nums[mid]<nums[right])
                {
                    right=mid;
                    mid=(right+left)/2;
                }
            }
        }
        if(target>nums[pivot])
            return -1;
        if(target==nums[pivot])
            return pivot;
        if(target>=nums[0])
        {
            int i=0,j=pivot,k=j/2;
            if(nums[i]==target)
                return i;
            if(nums[j]==target)
                return j;
            while(j-i>=2)
            {
                if(nums[k]==target)
                {
                    return k;
                }
                if(target<nums[k])
                {
                    j=k;
                    k=(i+j)/2;
                }
                if(target>nums[k])
                {
                    i=k;
                    k=(i+j)/2;
                }
            }
        }
        else
        {
            int i=pivot,j=nums.size()-1,k=(i+j)/2;
            if(nums[i]==target)
                return i;
            if(nums[j]==target)
                return j;
            while(j-i>=2)
            {
                if(nums[k]==target)
                {
                    return k;
                }
                if(target<nums[k])
                {
                    j=k;
                    k=(i+j)/2;
                }
                if(target>nums[k])
                {
                    i=k;
                    k=(i+j)/2;
                }
            }
        }
        }
        return -1;
        
            
        
    }
};
